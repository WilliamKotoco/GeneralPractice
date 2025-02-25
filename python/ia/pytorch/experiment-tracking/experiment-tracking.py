import torch
from torch import nn
import torchvision
from torchvision.transforms import v2
from torch.utils.data import DataLoader
from torchinfo import summary
from torcheval.metrics import MulticlassAccuracy
import myutils


#  For experiment tracking:
from torch.utils.tensorboard  import SummaryWriter

PATH = "/home/willao/Documents/Github/GeneralPractice/python/ia/pytorch/transfer-learning/data"

TRAIN_PATH = PATH + "/train"
TEST_PATH = PATH + "/test"

weights_1 = torchvision.models.EfficientNet_V2_L_Weights.DEFAULT

auto_transforms = weights_1.transforms()


train_dataset = torchvision.datasets.ImageFolder(
    root=TRAIN_PATH, transform=auto_transforms
)

test_dataset = torchvision.datasets.ImageFolder(
    root=TEST_PATH, transform=auto_transforms
)


train_dataloader = DataLoader(
    dataset=train_dataset, batch_size=32, shuffle=True, num_workers=4
)

test_dataloader = DataLoader(
    dataset=test_dataset, batch_size=32, shuffle=False, num_workers=4
)

DEVICE = 'cuda'

# Setting up the model
model1 = torchvision.models.efficientnet_v2_l(weights=weights_1).to(DEVICE)
for param in model1.features.parameters():
    param.requires_grad = False



#print(model.classifier)

# Replicates the classifier but adapted to our number of classes
classifier = nn.Sequential(
    nn.Dropout(p=0.4, inplace=True),
    nn.Linear(in_features=1280, out_features= len(train_dataset.classes), bias=True)
).to(DEVICE)


model1.classifier = classifier


loss_fn = nn.CrossEntropyLoss()

optim = torch.optim.SGD(params=model1.parameters(), lr = 0.015)

# Experiment tracking

# https://pytorch.org/docs/stable/tensorboard.html
writer = SummaryWriter(log_dir="experiments")

myutils.train(model=model1, train_dataloader=train_dataloader,
              test_dataloader=test_dataloader, DEVICE='cuda', optim=optim, loss_fn=loss_fn,
              EPOCHS=25, writer= writer)