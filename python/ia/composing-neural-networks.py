import numpy as np
import matplotlib.pyplot as plt


def ReLu(preactivation):
    return preactivation.clip(0.0) # values smaller than zero becomes 0

def shallow_network(x, activation_function, weights, thetas):
    hidden_units = np.zeros((len(thetas), len(x)))
    print(thetas)
    for i in range (len(thetas)):
        n1, n2 = thetas[i]
        hidden_units[i] = activation_function(n1 + n2 *x)

    weights = np.array(weights)
    return weights[0] + np.dot(weights[1:], hidden_units)




# # Plot two shallow neural networks and the composition of the two
def plot_neural_two_components(x_in, net1_out, net2_out, net12_out=None):

  # Plot the two networks separately
  fig, ax = plt.subplots(1,2)
  fig.set_size_inches(8.5, 8.5)
  fig.tight_layout(pad=3.0)
  ax[0].plot(x_in, net1_out,'r-')
  ax[0].set_xlabel('Net 1 input'); ax[0].set_ylabel('Net 1 output')
  ax[0].set_xlim([-1,1]);ax[0].set_ylim([-1,1])
  ax[0].set_aspect(1.0)
  ax[1].plot(x_in, net2_out,'b-')
  ax[1].set_xlabel('Net 2 input'); ax[1].set_ylabel('Net 2 output')
  ax[1].set_xlim([-1,1]);ax[1].set_ylim([-1,1])
  ax[1].set_aspect(1.0)
  plt.show()

  if net12_out is not None:
    # Plot their composition
    fig, ax = plt.subplots()
    ax.plot(x_in ,net12_out,'g-')
    ax.set_xlabel('Net 1 Input'); ax.set_ylabel('Net 2 Output')
    ax.set_xlim([-1,1]);ax.set_ylim([-1,1])
    ax.set_aspect(1.0)
    plt.show()


## creating first neural network
thetas_1 = [(0.0, -1.0), (0.0,1.0), (-0.67, 1.0)]
weights_1 = [1.0, -2.0, -3.0, 9.3]

## creating second neural network
thetas_2 = [(-0.6,-1.0), (0.2, 1.0), (-0.5, 1.0)]
weights_2 = [0.5, -1.0, -1.5, 2.0]

x = np.arange(-1,1,0.001)

nn1 = shallow_network(x,ReLu, weights_1, thetas_1)
nn2 = shallow_network(x,ReLu, weights_2, thetas_2)

plot_neural_two_components(x,nn1,nn2)

# creating a third neural network
nn3 = shallow_network(nn1, ReLu, weights_2, thetas_2)

plot_neural_two_components(x, nn1,nn2,nn3)
