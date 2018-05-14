import numpy as np
import matplotlib.pyplot as plt

q2 = np.genfromtxt("caos.dat", usecols = (0))
p2 = np.genfromtxt("caos.dat", usecols = (1))
q1 = np.genfromtxt("caos.dat", usecols = (2))
p1 = np.genfromtxt("caos.dat", usecols = (3))
t = np.genfromtxt("caos.dat", usecols = (4))

plt.scatter(p2,q2, s = 1)
plt.title("Gráfica de q2 vs p2")
plt.ylabel("q2")
plt.xlabel("p2")
"""fig, ax = plt.subplots(4,sharex="all")
ax[0].scatter(t, q1, label = "q1", s = 0.01)
ax[1].scatter(t, q2, label = "q2", s = 0.01)
ax[2].scatter(t, p1, label = "p1", s = 0.01)
ax[3].scatter(t, p2, label = "p2", s = 0.01)"""
plt.savefig("caos.pdf")
