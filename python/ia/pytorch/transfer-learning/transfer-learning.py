import torch
from torch import nn
import torchvision
from torchvision.transforms import v2
from torch.utils.data import DataLoader
from torchinfo import summary
from torcheval.metrics import MulticlassAccuracy

TRAIN_PATH = "data/train"
TEST_PATH = "data/test"

# Automatic transform creation based on model weights
# https://pytorch.org/vision/0.20/models.html


# Default gets the best weights
weights = torchvision.models.EfficientNet_V2_L_Weights.DEFAULT

auto_transforms = weights.transforms()


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
model = torchvision.models.efficientnet_v2_l(weights=weights).to(DEVICE)

# print(summary(model=model, col_names=['trainable']))

# We need to freeze back layers (so they are not trainable) and change the classifier
# head to train on 3 classes (pizza, steak, sushi)

for param in model.features.parameters():
    param.requires_grad = False



#print(model.classifier)

# Replicates the classifier but adapted to our number of classes
classifier = nn.Sequential(
    nn.Dropout(p=0.4, inplace=True),
    nn.Linear(in_features=1280, out_features= len(train_dataset.classes), bias=True)
).to(DEVICE)


model.classifier = classifier


loss_fn = nn.CrossEntropyLoss()

optim = torch.optim.SGD(params=model.parameters(), lr = 0.015)



EPOCHS = 50

acc = MulticlassAccuracy(device=DEVICE)
for epoch in range(EPOCHS):
    train_loss = 0
    for x, y in train_dataloader:
        model.train()

        x = x.to(DEVICE)
        y = y.to(DEVICE)
        y_pred = model(x)

        # calculate loss  per batch:
        loss = loss_fn(y_pred, y)
        train_loss += loss

        optim.zero_grad()

        loss.backward()

        optim.step()

    # avg loss per epoch
    train_loss /= len(train_dataloader)

    model.eval()
    test_loss = 0
    with torch.inference_mode():
        for x, y in test_dataloader:

            x = x.to(DEVICE)
            y = y.to(DEVICE)

            y_pred = model(x)

            loss = loss_fn(y_pred, y)
            test_loss += loss
            y_pred_classes = torch.argmax(y_pred, dim=1)
            acc.update(y_pred_classes, y)

        test_loss /= len(test_dataloader)

    print(
        f"Epoch {epoch}, acc: {acc.compute()} train loss: {train_loss:.4f}, test loss: {test_loss:.4f}"
    )
    acc.reset()
