from torchvision import datasets
from torchvision import transforms

from torch.utils.data import DataLoader
import matplotlib.pyplot as plt

train_data = datasets.FashionMNIST(root='data', train=True, download=True, transform=transforms.ToTensor())
test_data = datasets.FashionMNIST(root='data', train=False, download=True, transform=transforms.ToTensor())


image, _ = train_data[34]

plt.imshow(image.squeeze(), cmap='gray')
plt.show()

# Creating a dataloader to iterate over a dataset:
# https://pytorch.org/tutorials/beginner/basics/data_tutorial.html#creating-a-custom-dataset-for-your-files

train = DataLoader(dataset=train_data, batch_size=32, shuffle=True)

test = DataLoader(dataset=test_data, batch_size=32, shuffle=False)


print(f"{len(train)} batches of {train.batch_size} images")

# transforms dataloader into iterable
example_train_features = next(iter(train))

print(example_train_features[0].shape)

