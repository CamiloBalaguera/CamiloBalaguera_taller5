import numpy as np
import matplotlib.pyplot as plt

q2 = np.genfromtxt("caos.dat", usecols = (0))
p2 = np.genfromtxt("caos.dat", usecols = (1))

plt.plot(q2,p2)
plt.title("Gráfica de q2 vs p2")
plt.xlabel("q2")
plt.ylabel("p2")
plt.savefig("caos.pdf")
