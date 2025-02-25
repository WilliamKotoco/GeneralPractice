import torch

from torchvision import datasets, transforms
from torch.utils.data import DataLoader

# Dataset uses the ImageFolder standard:
# https://pytorch.org/vision/main/generated/torchvision.datasets.ImageFolder.html#torchvision.datasets.ImageFolder


TRAIN_PATH = "data/train"
TEST_PATH = "data/test"


# more image transformations to apply:
# https://pytorch.org/vision/0.9/transforms.html
dataset_transforms = transforms.Compose(
    [
        transforms.Resize(size=(224, 224)),
        transforms.RandomHorizontalFlip(p=0.5),
        transforms.ToTensor(),
    ]
)


train_data = datasets.ImageFolder(root=TRAIN_PATH, transform=dataset_transforms)

test_data = datasets.ImageFolder(root=TRAIN_PATH, transform=dataset_transforms)


CLASS_NAMES = train_data.classes


train_dataloader = DataLoader(
    dataset=train_data, batch_size=32, num_workers=4, shuffle=True
)


test_dataloader = DataLoader(
    dataset=test_data, batch_size=32, num_workers=4, shuffle=False
)
