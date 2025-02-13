import torch.optim.sgd
from torchvision import datasets
from torchvision import transforms
import torch
from torch import nn
from torcheval.metrics import MulticlassAccuracy

from torchmetrics import ConfusionMatrix
from torch.utils.data import DataLoader
import mlxtend.plotting.plot_confusion_matrix as pltconfmat
import matplotlib.pyplot as plt

BATCH_SIZE = 32

DEVICE = "cuda"


train_data = datasets.FashionMNIST(
    root="data", train=True, download=True, transform=transforms.ToTensor()
)

test_data = datasets.FashionMNIST(
    root="data", train=False, download=True, transform=transforms.ToTensor()
)

image, _ = train_data[34]

plt.imshow(image.squeeze(), cmap="gray")
plt.show()

# Creating a dataloader to iterate over a dataset:
# https://pytorch.org/tutorials/beginner/basics/data_tutorial.html#creating-a-custom-dataset-for-your-files

train = DataLoader(dataset=train_data, batch_size=BATCH_SIZE, shuffle=True)

test = DataLoader(dataset=test_data, batch_size=BATCH_SIZE, shuffle=False)


print(f"{len(train)} batches of {train.batch_size} images")


# transforms dataloader into iterable
example_train_features = next(iter(train))

print(example_train_features[0].shape)


print(len)


# create models to test
dumb = nn.Sequential(
    nn.Flatten(),  # flatten the 2d image to 1d
    nn.Linear(in_features=28 * 28, out_features=10),
    nn.Linear(in_features=10, out_features=len(train_data.classes)),
).to(DEVICE)


dumb_optim = torch.optim.SGD(dumb.parameters(), lr=0.1)
dumb_loss = nn.CrossEntropyLoss()


linear_model = nn.Sequential(
    nn.Flatten(),
    nn.Linear(in_features=28 * 28, out_features=10),
    nn.ReLU(),
    nn.Linear(in_features=10, out_features=len(train_data.classes)),
    nn.ReLU(),
).to(DEVICE)


linear_optim = torch.optim.SGD(linear_model.parameters(), lr=0.1)


# Replicates the TINY VGG architecture
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
            nn.Linear(in_features=hidden_units * 7 * 7, out_features=output_shape),
        )

    def forward(self, x):
        # x = self.conv_block1(x)
        # print(x.shape)
        # x = self.conv_block2(x)
        # print(x.shape)
        # return self.classifier(x)
        return self.classifier(self.conv_block2(self.conv_block1(x)))


# fashion MNIST is grey scale, so input shape = 1 and not 3
model_cnn = CNN_model(
    input_shape=1, output_shape=len(train_data.classes), hidden_units=10
).to(DEVICE)

cnn_optim = torch.optim.SGD(params=model_cnn.parameters(), lr=0.015)


# train and test code
model = model_cnn

loss_fn = dumb_loss
optim = cnn_optim


EPOCHS = 20

acc = MulticlassAccuracy(device=DEVICE)
conf_mat = ConfusionMatrix(task="multiclass", num_classes=len(train_data.classes))
for epoch in range(EPOCHS):
    train_loss = 0
    for x, y in train:
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
    train_loss /= len(train)

    model.eval()
    test_loss = 0
    with torch.inference_mode():
        for x, y in test:

            x = x.to(DEVICE)
            y = y.to(DEVICE)

            y_pred = model(x)

            loss = loss_fn(y_pred, y)
            test_loss += loss
            y_pred_classes = torch.argmax(y_pred, dim=1)
            acc.update(y_pred_classes, y)

        test_loss /= len(test)

    print(
        f"Epoch {epoch}, acc: {acc.compute()} train loss: {train_loss:.4f}, test loss: {test_loss:.4f}"
    )
    acc.reset()

model.eval()
preds = []

with torch.inference_mode():
  for x, y in test:
    x= x.to(DEVICE)
    y = y.to(DEVICE)

    y_pred = model(x)

    loss = loss_fn(y_pred, y)

    y_pred_classes = torch.argmax(y_pred, dim=1)
    acc.update(y_pred_classes, y)
    preds.append(y_pred.to('cpu'))

y_pred_tensor = torch.cat(preds)

confmat_tensor = conf_mat(preds=y_pred_tensor, target = test_data.targets)

fix, ax = pltconfmat(
    conf_mat=confmat_tensor.numpy(),
    class_names=train_data.classes
)
plt.show()