import PIL.Image
import torch
from torch import nn
import os
from torcheval.metrics import MulticlassAccuracy
from torchvision import datasets
from torchvision.transforms import v2
from torchvision import transforms
from torch.utils.data import DataLoader, Dataset
from torchinfo import summary
import pathlib
import myutils

# Dataset uses the ImageFolder standard:
# https://pytorch.org/vision/main/generated/torchvision.datasets.ImageFolder.html#torchvision.datasets.ImageFolder


TRAIN_PATH = "data/train"
TEST_PATH = "data/test"


# more image transformations to apply:
# https://pytorch.org/vision/main/transforms.html
# https://pytorch.org/vision/main/auto_examples/transforms/plot_transforms_getting_started.html#sphx-glr-auto-examples-transforms-plot-transforms-getting-started-py
train_transforms = v2.Compose(
    [
        v2.Resize(size=(224, 224)),
        v2.RandomHorizontalFlip(p=0.5),
        v2.TrivialAugmentWide(num_magnitude_bins=32),
        v2.RandomVerticalFlip(p=0.5),
        v2.RandomRotation(degrees=30),
        v2.ColorJitter(brightness=0.2, contrast=0.2, saturation=0.2, hue=0.1),
        # ToTensor is deprecated, use this instead:
        v2.Compose([v2.ToImage(), v2.ToDtype(torch.float32, scale=True)]),
    ]
)

test_transforms = v2.Compose(
    [
        v2.Resize(size=(224, 224)),
        # ToTensor is deprecated, use this instead:
        v2.Compose([v2.ToImage(), v2.ToDtype(torch.float32, scale=True)]),
    ]
)

class_names = sorted(entry.name for entry in os.scandir(TRAIN_PATH))


class CustomDataset(Dataset):
    def __init__(self, target_dir, transform):
        super().__init__()
        self.paths = list(pathlib.Path(target_dir).glob("*/*.jpg"))

        self.transforms = transform

        self.classes = sorted(entry.name for entry in os.scandir(TRAIN_PATH))

        self.class_to_idx = {class_n: i for i, class_n in enumerate(class_names)}

    def load_image(self, index: int) -> PIL.Image.Image:
        image_path = self.paths[index]
        return PIL.Image.open(image_path)

    def __len__(self):
        return len(self.paths)

    def __getitem__(self, index):
        img = self.load_image(index)

        class_name = self.paths[index].parent.name

        class_idx = self.class_to_idx[class_name]

        if self.transforms is not None:
            return self.transforms(img), class_idx
        else:
            return img, class_idx


train_dataset = CustomDataset(TRAIN_PATH, train_transforms)

test_dataset = CustomDataset(TEST_PATH, test_transforms)


# myutils.plot_random_images(train_dataset, train_dataset.classes, 5)


train_dataloader = DataLoader(
    dataset=train_dataset, batch_size=32, num_workers=4, shuffle=True
)


test_dataloader = DataLoader(
    dataset=test_dataset, batch_size=32, num_workers=4, shuffle=False
)


class CNN_model(nn.Module):

    def __init__(self, input_shape: int, output_shape: int, hidden_units: int):

        print(hidden_units, input_shape, output_shape)
        super().__init__()

        self.conv_block1 = nn.Sequential(
            nn.Conv2d(
                in_channels=input_shape,
                out_channels=hidden_units,
                kernel_size=3,
                stride=1,
                padding=1,
            ),
            nn.ReLU(),
            nn.Conv2d(
                in_channels=hidden_units,
                out_channels=hidden_units,
                kernel_size=3,
                stride=1,
                padding=1,
            ),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2),
        )

        self.conv_block2 = nn.Sequential(
            nn.Conv2d(
                in_channels=hidden_units,
                out_channels=hidden_units,
                kernel_size=3,
                stride=1,
                padding=1,
            ),
            nn.ReLU(),
            nn.Conv2d(
                in_channels=hidden_units,
                out_channels=hidden_units,
                kernel_size=3,
                stride=1,
                padding=1,
            ),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2),
        )

        self.classifier = nn.Sequential(
            nn.Flatten(),
            nn.Linear(in_features=hidden_units * 56 * 56, out_features=output_shape),
        )

    def forward(self, x):
        # x = self.conv_block1(x)
        # print(x.shape)
        # x = self.conv_block2(x)
        # print(x.shape)
        # return self.classifier(x)
        return self.classifier(self.conv_block2(self.conv_block1(x)))


DEVICE = "cuda"

# fashion MNIST is grey scale, so input shape = 1 and not 3
model_cnn = CNN_model(
    input_shape=3, output_shape=len(train_dataset.classes), hidden_units=10
).to(DEVICE)

cnn_optim = torch.optim.SGD(params=model_cnn.parameters(), lr=0.015)

# train and test code
model = model_cnn

loss_fn = nn.CrossEntropyLoss()
optim = cnn_optim


print(summary(model_cnn, input_size=[1,3,224,224]))


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
