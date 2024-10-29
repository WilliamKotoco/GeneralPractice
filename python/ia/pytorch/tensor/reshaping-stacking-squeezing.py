import torch

x = torch.arange(0.0, 10.0)

print(x, x.shape)
# Reshape reshapes an input tensor to a defined shape
# View - Returns a view of an input tensor of certain shape but keep the same memory as the original
x_reshape = x.reshape(2, 5)
print(x_reshape, x_reshape.shape)

z = x.view(1, 10)
# view shares the memory. Changing z will change x
z[0] = 5
print("z == x ?", z == x)
# Stackig - combine multiple tensor on top of each other (Vstack) or side by side (hstack)
x_stacked = torch.stack([x, x, x, x], dim=0)
print(x_stacked)

x_stacked = torch.stack([x, x, x, x], dim=1)
print(x_stacked)

# Squeeze - removes all '1' dimensions from a tensor

y = torch.rand(1, 1, 10)
print(y, y.shape)

print(y.squeeze(), y.squeeze().shape)


# Permute
#
print("--" * 15)

print("permute: ")
image = torch.rand(size=(224, 224, 3))  # height, width and color channels
print(image.shape)

image_permute = image.permute(2, 0, 1)
print(image_permute.shape)
