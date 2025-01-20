from torch import nn

import helper
import torch 

def printer(label, pred):
    for pair in zip(label,pred):
        print(pair)

X = torch.arange(0,100,0.2).unsqueeze(dim=1)

weight = 3
bias = 35.35
y = weight * X + bias


train_split_size = int(len(X) * 0.8)

X_train, Y_train = X[:train_split_size], y[:train_split_size]

X_test, y_test =X[train_split_size:], y[train_split_size:]



class LinearRegresion(nn.Module):

    def __init__(self):
        super().__init__()

        # initialize weights with random values
        self.weights = nn.Parameter(torch.randn(1,
                                               requires_grad=True))
        

        self.bias = nn.Parameter(torch.randn(1,
                                            requires_grad=True))


    # Defines a computatio in the model    
    def forward(self, x: torch.Tensor) -> torch.Tensor:
        return self.weights * x + self.bias 
    


model = LinearRegresion()


# Making predictions
with torch.inference_mode():
    inference = model(X_test)

printer(y_test, inference)


helper.plot_predictions(X_train, Y_train, X_test, y_test, inference)


loss_fn = nn.L1Loss()

optimizer = torch.optim.SGD(momentum=0.984, lr=0.001, params=model.parameters())
print(model.parameters)


epochs = 500

for epoch in range(epochs):
    model.train()

    pred = model(X_train)

    loss = loss_fn(pred, Y_train)


    print(f"Loss: {loss}");


    # zero the optimizer
    optimizer.zero_grad()

    # backpropagation
    loss.backward()    

    # gradient descent optimizing
    optimizer.step()

    print(model.state_dict())
    print(f"Weights: {weight}, Bias: {bias}")

with torch.inference_mode():
    inference = model(X_test)



helper.plot_predictions(X_train, Y_train, X_test, y_test, inference)


