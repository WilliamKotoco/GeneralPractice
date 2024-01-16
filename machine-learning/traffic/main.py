import scipy as sp 
import matplotlib.pyplot as plt
import numpy as np
import math
data = sp.genfromtxt("web_traffic.tsv", delimiter="\t")

# The error function will be the squared distance of the model's prediction to real data

def error(f, x, y):
    return sp.sum((f(x)-y)**2)
# separate dimensions in two vectors, one will contail the hours and other will contain the web hits in that particular hour 

x = data[:, 0]
y = data[:, 1]

x = x[~sp.isnan(y)] # remove invalid data from x 
y = y[~sp.isnan(y)] # remove invalid data from y

plt.scatter(x,y)
plt.title("Web traffic last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*24 for w in range(10)],
           ['week %i'%w for w in range(10)])
plt.autoscale(tight=True)
plt.grid()
#plt.show()


# for what is showed, we can try to fit a function of degree 2
f2p = np.polyfit(x,y,2)

f2 = np.poly1d(f2p)

fx = np.linspace(0, x[-1], 1000) # values for plotting
plt.plot(fx, f2(fx), linewidth=4, color = 'green')

plt.show()

#between the week 3 and 4 we have a massive change and all dots are more joined
turning_point = int(3.5 * 7 * 24) # turning point in hours
#data before turning point 
xb = x[:turning_point]
yb = y[:turning_point]

# data after turning_point
xa = x[turning_point:]
ya = y[turning_point:]

fa = np.poly1d(np.polyfit(xa,ya,1))
fb = np.poly1d(np.polyfit(xb,yb,1))

fxa = np.linspace(0, xa[-1], 1000)
fxb = np.linspace(0, xb[-1], 1000)

plt.scatter(x,y)
plt.title("Web traffic last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*24 for w in range(10)],
           ['week %i'%w for w in range(10)])
#plt.autoscale(tight=True)
plt.yticks([0, 1000, 2000, 3000, 4000, 5000, 6000])

plt.grid()
plt.plot(fxa, fa(fxa), linewidth = 4, color = 'red' )
plt.plot(fxb, fb(fxb), linewidth = 4, color = 'blue')
plt.show()

fa_error = error(fa, xa, ya)
fb_error = error(fb, xb, yb)

# now, let us try to fit a model of degree 2 for the last week and see how it behave

last_week = 4 * 7 * 24 
xl = x[last_week:]
yl = y[last_week:]
fl = np.poly1d(np.polyfit(xa,ya,2))
flx = np.linspace(0, xa[-1],1000)
plt.scatter(x,y)
plt.title("Web traffic last month")
plt.xlabel("Time")
plt.ylabel("Hits/hour")
plt.xticks([w*7*24 for w in range(10)],
           ['week %i'%w for w in range(10)])
plt.autoscale(tight=True)
plt.yticks([0, 1000, 2000, 3000, 4000, 5000, 6000])

plt.grid()
plt.plot(flx, fl(flx), linewidth = 4, color = 'red' )
plt.show()

print(error(fl, xa,ya))
