import torch

tensor1 = torch.rand(4, 4)
tensor2 = torch.rand(4, 4)

print(tensor1)
print(tensor2)

# Element-wise multiplication
print(f"Element-wise multiplication:  {tensor1 * tensor2}")

# Matrix multiplication
print(f"Matrix multiplication: {torch.matmul(tensor1, tensor2)}")


tensor1 = torch.rand(3, 2)
tensor2 = torch.rand(3, 2)
print("-" * 30)
# we cannot multiply them, but we can multiply the transpose
print(tensor2)
print(tensor2.T)

# now we can multiply them
print(f"Matrix multiplication: {torch.matmul(tensor1, tensor2.T)}")

# we also have max min sum etc but it is t rivial

print("="*30)
tensor1 = torch.arange(3).reshape(3,1)
tensor2 = torch.arange(2).reshape(1,2)
print(tensor1)
print(tensor2)
print("Python creates will create a 3x2 matrix to match ")
print(tensor2 + tensor1)
