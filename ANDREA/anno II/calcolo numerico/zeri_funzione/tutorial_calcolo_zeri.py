import numpy as np
from scipy import optimize

# SLIDE 2

# definisco una funzione f equivalente a cos(x) - x
f = lambda x: np.cos(x) - x
# fsolve -> trova gli zeri di una funzione non lineare (param 1) a partire da una certa x (param 2).
# Quindi x0 (param 2) non è un intorno, se mai un intorno iniziale
r = optimize.fsolve(f, -2)
print("r=", r)
# verifichiamo che la soluzione sia una radice
result = f(r)
print("result=", result)

# ESERCIZIO SLIDE 2
g = lambda x : 1 / x
# ovviamente, 1/x non ha zeri. In questo caso fsolve da un warning (non un error) e stampa qualcosa del tipo
# "l'iterazione non sta dando progressi". Per catchare il warning si potrebbe usare un modulo apposito,
# in modo da rifiutare valori inesatti
r = optimize.fsolve(g, 0)
print("r=", r)
result = g(r)
print("result=", result)