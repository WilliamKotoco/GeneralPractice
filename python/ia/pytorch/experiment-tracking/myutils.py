import torch
from torch.utils.data import Dataset
import matplotlib.pyplot as plt
from typing import List, Tuple
from torch import nn
import random
from torcheval.metrics import MulticlassAccuracy
from torch.utils.tensorboard import SummaryWriter


def plot_random_images(dataset: Dataset, classes: List[str], num_images=5):

    random_samples_id = random.sample(range(len(dataset)), k=num_images)

    plt.figure(figsize=(16, 8))

    for i, target in enumerate(random_samples_id):
        # dataset returns img, idx
        img, label = dataset[target][0], dataset[target][1]

        print(img.shape)

        img = torch.permute(img, (2, 1, 0))

        plt.subplot(1, num_images, i + 1)
        plt.imshow(img)
        plt.axis("off")
        title = f"Class: {classes[label]}"
        plt.title(title)

        plt.show()

        EPOCHS = 50


def train(
    model,
    train_dataloader,
    test_dataloader,
    DEVICE,
    optim,
    loss_fn,
    EPOCHS,
    writer: SummaryWriter,
):
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

        writer.add_scalars(
            main_tag="Loss",
            tag_scalar_dict={
                "train_loss": train_loss,
                "test_loss": test_loss,
            },
            global_step=epoch
        )

        writer.add_scalars(
            main_tag="Accuracy", tag_scalar_dict={"Accuracy": acc.compute()}, global_step=epoch
        )

        writer.close()
        print(
            f"Epoch {epoch}, acc: {acc.compute()} train loss: {train_loss:.4f}, test loss: {test_loss:.4f}"
        )
        acc.reset()


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

