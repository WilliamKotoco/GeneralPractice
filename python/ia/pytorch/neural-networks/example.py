import sklearn
from sklearn.datasets import make_circles
import pandas as pd

from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt


from helper import plot_decision_boundary
import torch
from torch import nn
n_samples = 92314


x,labels = make_circles(n_samples=n_samples,
                        noise=0.05,
                        random_state=43)





# visualizing data
circles = pd.DataFrame({"x1": x[:,0],
                        "x2": x[:,1],
                        "label": labels})

print(circles.head(10))


# visualizing with mat plot ib
# plt.scatter(x=x[:,0],
#             y = x[:,1],
#             c =  labels,
#             cmap=plt.cm.RdYlBu)
# plt.show()

# Turning data into pytorch tensors
x = torch.from_numpy(x)
labels = torch.from_numpy(labels)

# convert labels from integer to torch float
labels = labels.type(torch.float)

# convert train from double to float
x = x.type(torch.float)

x_train, x_test, labels_train, labels_test = train_test_split(x,labels, test_size=0.2, random_state=42)

device = "cuda" if torch.cuda.is_available() else "cpu"


print(x_train.dtype)
print (x.shape)
# Constructing a mode

class CircleModel(nn.Module):
    def __init__(self):
        super().__init__()

        # creating first layer of the neural network
        self.layer1 = nn.Linear(in_features = 2, out_features= 5) # takes in 2 features (x.shape)
        
        self.layer2 = nn.Linear(in_features=5, out_features= 1) # final classification layer that takes the 5 out features from the previous layer and classify into a single label


    # forward pass for our circle model
    def forward(self, x):
        return self.layer2(self.layer1(x))


model = CircleModel().to(device)

print(model)


# nn.Sequential implementes a neural network in which the forward function connects the layers sequentialy
# as we did in the forward function of CircleModel
model_replicated = nn.Sequential(
    nn.Linear(in_features=2, out_features=5),
    nn.Linear(in_features = 5, out_features=1)
).to(device)


print(model_replicated)
        

#setup the loss Binary Cross Entorpy, suitable for binary classification 
# Combines the Sigmoid activation function with the binary cross entropy loss
loss_function = nn.BCEWithLogitsLoss() 

# SGD optmizer
optimizer = torch.optim.SGD(params = model_replicated.parameters(),
                            lr=0.015)


# Training the model
epochs = 1000

# Data on the target device
x_train, labels_train = x_train.to(device), labels_train.to(device)
x_test, labels_test = x_test.to(device), labels_test.to(device)

for epoch in range (epochs):
    model_replicated.train()

    # forward pass 
    y_pred = model_replicated(x_train).squeeze()
    
    # Calculate loss 
    loss = loss_function(y_pred, labels_train)

    #optimizer
    optimizer.zero_grad()

    # backward propagation
    loss.backward()

    #gradient descent)
    optimizer.step()


# testing after training epoch

    model_replicated.eval()

    with torch.inference_mode():
        
        test_logits = model_replicated(x_test).squeeze()
        test_pred = torch.round(torch.sigmoid(test_logits)) # transform raw data into predictions using the sigmoid funciotn (check BCE)

        loss_test = loss_function(test_pred, labels_test)
        
        acc = torch.sum(test_pred == labels_test)/len(labels_test)

        print(f"Epoch {epoch}, acuracy: {acc:.2f}, train_loss: {loss:.5f}, test_loss {loss_test:.5f}")



print("Visualizing")
# visualize the predictions
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.title(("Train"))
plot_decision_boundary(model_replicated, x_train, labels_train)
plt.figure(figsize=(12,6))
plt.subplot(1,2,1)
plt.title(("Test"))
plot_decision_boundary(model_replicated, x_test, labels_test)
plt.show()
