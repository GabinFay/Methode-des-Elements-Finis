import numpy as np
import matplotlib.pyplot as plt

plt.close("all")
data = np.genfromtxt("fort.3", delimiter = "   ")

plt.figure("erreur relative")
plt.plot(data[:,2], data[:,0], label = "erreur quadratique relative")
plt.plot(data[:,2], data[:,1], label = "erreur maximale relative")
plt.title("Domaine 1\nCas n°1 Quadrangles\nErreur relative en fonction du pas h")
plt.xlabel("Pas h")
plt.ylabel("Erreur relative")
plt.legend()

plt.figure("log erreur relative")
plt.loglog(data[:,2], data[:,0], label = "log erreur quadratique relative")
plt.loglog(data[:,2], data[:,1], label = "log erreur maximale relative")
plt.title("Domaine 1\nCas n°1 Quadrangles\nlog erreur relative en fonction du pas h")
plt.xlabel("log(h)")
plt.ylabel("log erreur relative")
plt.legend()