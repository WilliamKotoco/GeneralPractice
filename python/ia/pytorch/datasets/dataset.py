import torch 

from torch.utils.data import DataLoader
from torchvision import transforms


# Dataset uses the ImageFolder standard: 
# https://pytorch.org/vision/main/generated/torchvision.datasets.ImageFolder.html#torchvision.datasets.ImageFolder


TRAIN_PATH = "data/train"
TEST_PATH = "data/test"


# more image transformations to apply:
# https://pytorch.org/vision/0.9/transforms.html
dataset_transforms = transforms.Compose([
    transforms.Resize(size=(224,224)),
    transforms.RandomHorizontalFlip(p=0.5),
    transforms.ToTensor()
])