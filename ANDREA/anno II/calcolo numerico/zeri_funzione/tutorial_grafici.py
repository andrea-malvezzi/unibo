import numpy as np
import matplotlib.pyplot as plt

# si, posso usare ; in py. Crazy
a = -1; b = 1
x = np.linspace(a, b)           # creo un array di n punti [50 di default] tra a e b
plt.figure(figsize=(12, 6))     # creo un grafico vuoto grande 12 ed alto 6
plt.plot(x, x - np.cos(x))      # voglio plottare la funzione x - cos(x)
plt.plot([a, b], [0, 0], 'g')   # plot collega i punti nell'intervallo a,b con un segmento.
                                # Così dico che voglio un segmento rialzato di 0, verde ('g')
plt.grid(True)                  # aggiunge una griglia in background

plt.show()