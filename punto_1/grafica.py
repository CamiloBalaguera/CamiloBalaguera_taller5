import numpy as np
import matplotlib.pyplot as plt

X = np.genfromtxt("datos.dat")[0]
Y = np.genfromtxt("datos.dat")[0]
V = np.genfromtxt("datos.dat")[1:np.size(X)+1]
Ex = np.genfromtxt("datos.dat")[np.size(X)+2:-np.size(X)+1]
Ey = np.genfromtxt("datos.dat")[-np.size(X):]
valx = X.tolist()
valy = Y.tolist()
valx = list(set(valx))
valy = list(set(valy))
X = np.array(valx)
Y = np.array(valy)
plt.subplot(2,1,1)
plt.imshow(np.transpose(V), extent=(0,5,0,5))
plt.title("Potencial")
plt.subplot(2,1,2)
plt.streamplot(X/4,Y/4,np.transpose(Ex),np.transpose(Ey), color = Ex, cmap="plasma")
plt.title("Campo electrico")
plt.savefig("placas.pdf")
