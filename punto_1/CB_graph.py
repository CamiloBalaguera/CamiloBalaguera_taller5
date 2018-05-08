import numpy as np
import matplotlib.pyplot as plt

numero = np.genfromtxt("datos.txt", usecols = (0))
pos = np.genfromtxt("datos.txt", usecols = (0))
amp = np.genfromtxt("datos.txt", usecols = (1))

n = int(numero[0]) # Numero de espacios correspondientes a todas las posiciones

posicion = pos[1:n] # Lista de todas las posiciones
amp1 = amp[1:n] # Lista de amplitudes para todas las posiciones en tiempo 0
amp2 = amp[n:2*n-1] # Lista de amplitudes para todas las posiciones en tiempo 1
amp3 = amp[2*n:3*n-1] # Lista de amplitudes para todas las posiciones en tiempo 2
amp4 = amp[3*n:4*n-1] # Lista de amplitudes para todas las posiciones en tiempo 3
amp5 = amp[4*n:5*n-1] # Lista de amplitudes para todas las posiciones en tiempo 4
plt.plot(posicion,amp1, label = "Tiempo 0")
plt.plot(posicion,amp2, label = "Tiempo 1")
plt.plot(posicion,amp3, label = "Tiempo 2")
plt.plot(posicion,amp4, label = "Tiempo 3")
plt.plot(posicion,amp5, label = "Tiempo 4")
plt.legend()
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.savefig("graf.png")


