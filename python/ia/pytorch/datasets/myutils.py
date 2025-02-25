import torch
from torch.utils.data import Dataset
import matplotlib.pyplot as plt
from typing import List, Tuple
import random
from torcheval.metrics import MulticlassAccuracy

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


def train(model, train_dataloader, test_dataloader, DEVICE, optim, loss_fn, EPOCHS):
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
