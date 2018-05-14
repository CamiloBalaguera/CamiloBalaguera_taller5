import numpy as np
import matplotlib.pyplot as plt

q2 = np.genfromtxt("caos.dat", usecols = (0))
p2 = np.genfromtxt("caos.dat", usecols = (1))

plt.plot(p2,q2)
plt.title("Gráfica de q2 vs p2")
plt.ylabel("q2")
plt.xlabel("p2")
plt.savefig("caos.pdf")
