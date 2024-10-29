# documentation for tensor: https://pytorch.org/docs/stable/tensors.html
import torch
import numpy as np


scalar = torch.tensor(7)

print(scalar.ndim)

# get tensor back as python int
print(scalar.item())


# creates a vector with 2 elements
vector = torch.tensor([7, 7])
print(vector, vector.ndim, vector.shape)


matrix = torch.tensor([[7, 8], [9, 10]])

print(matrix, matrix.ndim, matrix.shape)

# you will not have to create those tensors by hand, usually it is done behind the curtain
#
#  Random tensors: Many neural networks start with tensors full of random numbers and then adjust those random numbers
# to better represent the data
#
# start with random numbers -> look at data -> update random numbers

random_tensor = torch.rand(3, 4)

print("Random tensor: ")
print(random_tensor, random_tensor.ndim, random_tensor.shape)


print("ANother random tensor: ")
random_tensor = torch.rand(5, 3, 4)

print(random_tensor, random_tensor.ndim, random_tensor.shape)

print("Example with image-like")

random_tensor = torch.rand(
    size=(244, 244, 3)
)  # height, width and RGB An image is a sobreposition of three images a RED, a GREEN and a BLUE
print(random_tensor, random_tensor.ndim, random_tensor.shape)


## You also have tensors with zeros and with ones
zeros = torch.zeros(size=(3, 4))
ones = torch.ones(size=(3, 4))

print(zeros)
print(ones)

## It is also possible to use ranges
print("Tensor with rangess")
one_to_ten = torch.arange(1, 11)

arange = torch.arange(start=0, end=1000, step=77)
print(one_to_ten)
print(arange)

## More specific


# the last one is wether or not to track gradients
specific_tensor = torch.rand(
    size=(3, 4, 5),
    dtype=torch.float16,
    device="cpu",
    requires_grad=False,  # wether or not to track gradients
)
print(specific_tensor.device, specific_tensor.requires_grad)


# find max and min in tensors
tensor = torch.rand(50, 50)

# argmin and argmax returns the index of the maximum position
# it retuns the absolute index
print(tensor.argmin())

print(tensor.flatten()[tensor.argmin()])

print(tensor.argmax())

print(tensor.flatten()[tensor.argmax()])


# We can convert numpy to tensor and also tensor to numpy 


print("="*50)
# we can reduce the randomness by using seeds 
RANDOM_SEED = 42

torch.manual_seed(RANDOM_SEED)
almost_randon_tensor = torch.rand(3,4)
almost_randon_tensor2 = torch.rand(3,4)

print(almost_randon_tensor)
print(almost_randon_tensor2)

# the random seed works for only one generation
torch.manual_seed(RANDOM_SEED)
almost_random_tensor3 = torch.rand(3,4)
print(almost_randon_tensor == almost_random_tensor3)
