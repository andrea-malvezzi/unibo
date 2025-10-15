import random, math

def saluti(nome : str) -> None:
    r"""
    Stampa a schermo dei saluti diretti al nome inserito in input

    Parameters:
    nome(str): Il nome da salutare.
    """
    print(f"Ciao {nome}!")

def somma_e_prodotto(n1 : float, n2 : float) -> tuple[float, float]:
    r"""
    Presi in input due numeri n1 ed n2, ne ritorna somma e prodotto sotto forma di tupla di cui fare l'unpack.

    Parameters:
    n1 (float): Primo numero
    n2 (float): Secondo numero

    Returns:
    (float): n1 + n2
    (float): n1 * n2
    """
    somma = n1 + n2
    prodotto = n1 * n2
    return somma, prodotto

def cubo(n1 : float) -> float:
    r"""
    Eleva al cubo un numero n1.

    Parameters:
    n1 (float): Il numero da elevare al cubo.

    Returns:
    (float): Il numero n1 elevato al cubo
    """
    return n1**3

def elemento_per_elemento(f, x : tuple[float]) -> list[float]:
    r"""
    Presa in input una funzione f ed una tupla di float x, ritorna una lista
    della stessa lunghezza di x, i cui elementi sono gli f(xi).

    Parameters:
    f (function): La funzione da applicare elemento per elemento
    x (tuple): Una tupla di numeri float

    Returns:
    (list): Una tupla contenente gli f(xi)
    """
    # creo una lista di output con un certo spazio allocato per gestire bene la memoria
    y = [0] * len(x)

    # itero su x
    for i in range(len(x)):
        # estraggo l'elemento i-esimo
        xi = x[i]
        # salvo l'elemento i-esimo di x dopo avervi applicato f, all'interno dell'output
        y[i] = f(xi)
    
    return y

quadrato = lambda x: x**2

def test():
    r"""
    Prova tutte le funzioni implementate in questo file.
    """
    nome : str = "Andrea"

    n1 : float = 4.0
    n2 : float = 2.1

    x : tuple[float] = (-1.50, 2, 4, -4.71)

    saluti(nome)

    sp_res = somma_e_prodotto(n1, n2)
    print(f"Tipo di sp_res: {type(sp_res)}")
    print(f"Valore di sp_res: {sp_res}")

    x_cubo : tuple[float] = elemento_per_elemento(cubo, x)
    print(f"Tupla x elevata al cubo: {x_cubo}")

    n1_quad = quadrato(n1)
    print(f"{n1} al quadrato: {n1_quad}")

if __name__ == "__main__":
    test()