from types import new_class
import numpy as np
import matplotlib.pyplot as plt

# define a signalthat we can apply convolution to
x = [5.2, 5.3, 5.4, 5.1, 10.1, 10.3, 9.9, 10.3, 3.2, 3.4, 3.3, 3.1]

# Draw the signal
fig,ax = plt.subplots()
ax.plot(x, 'k-')
ax.set_xlim(0,11)
ax.set_ylim(0, 12)
plt.show()

# Now let's define a zero-padded convolution operation
# with a convolution kernel size of 3, a stride of 1, and a dilation of 1
# as in figure 10.2a-c.  Write it yourself, don't call a library routine!


def conv_3_1_1_zp(x_in, omega):
    x_out = np.zeros_like(x_in)

    n = len(x_in)

    # kernel size
    k = len(omega)

    x_padded = np.pad(x_in, pad_width=1, mode='constant', constant_values=0)

    x_out = np.zeros(n)

    for i in range(n):
        window = x_padded[i: i + k]

        # soma cada elemento da janela multiplicado pela convol8ução
        x_out[i] = np.sum(window * omega)

    return x_out

# convolution with kernel size of 3, stride of 2 and dilation of 1
def conv_3_2_1_zp(x_in, omega):
    n = int(np.ceil( len(x_in) /2))

    k = len(omega)

    x_padded = np.pad(x_in, pad_width=1, mode='constant', constant_values=0)


    x_out = np.zeros(n)

    for i in range(n):
        window = x_padded[i: i + k]
        x_out[i] = np.sum(window * omega)

    return x_out

# convolution with kernel size 5, stride of 1 and dilation of 1
def conv_5_1_1_zp(x_in, omega):

    n = len(x_in)

    k = 5

    x_padded = np.pad(x_in, pad_width= int((k-1)/2) , mode ='constant', constant_values=0)

    x_out = np.zeros(n)

    for i in range(n):
        x_window = x_padded[i: i + k]
        x_out[i] = np.sum(x_window * omega)

    return x_out

# convolution with kernel size of 3, stride of 1 and dilation of 2
def conv_3_1_2_zp(x_in, omega):

    n = len(x_in)

    k = 3

    x_padded = np.pad(x_in, pad_width=int((k-1) * 2 / 2), mode='constant', constant_values=0)

    x_out = np.zeros(n)

    for i in range(n):
        window = x_padded[i: i + k * 2 : 2]
        x_out[i] = np.sum(window * omega)
    return x_out



omega = [0.33, 0.33, 0.33]
h = conv_3_1_1_zp(x, omega)

print("Sum is ", np.sum(h))

# Draw the signal
fig,ax = plt.subplots()
ax.plot(x, 'k-',label='before')
ax.plot(h, 'r-',label='after')
ax.set_xlim(0,11)
ax.set_ylim(0, 12)
ax.legend()
plt.show()

omega = [-0.5, 0, 0.5]
h2 = conv_3_1_1_zp(x, omega)
fig,ax = plt.subplots()
ax.plot(x, 'k-',label='before')
ax.plot(h2, 'r-',label='after')
ax.set_xlim(0,11)
#ax.set_ylim(0, 12)
ax.legend()
plt.show()


omega = [0.33, 0.33, 0.33]
h3 = conv_3_2_1_zp(x, omega)

print(h)
print(h3)

omega2 = [0.2, 0.2, 0.2, 0.2, 0.2]

h4 = conv_5_1_1_zp(x, omega2)
print ("sum 5_1_1 is ", np.sum(h4))

fig,ax = plt.subplots()
ax.plot(x, 'k-',label='before')
ax.plot(h4, 'r-',label='after')
ax.set_xlim(0,11)
ax.set_ylim(0, 12)
ax.legend()
plt.show()


omega = [0.33, 0.33, 0.33]
h5 = conv_3_1_2_zp(x, omega)

print ("sum 3_1_2 os ", np.sum(h5))
fig,ax = plt.subplots()
ax.plot(x, 'k-',label='before')
ax.plot(h5, 'r-',label='after')
ax.set_xlim(0,11)
ax.set_ylim(0, 12)
ax.legend()
plt.show()
