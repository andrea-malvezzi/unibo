# ricordati di guardare il modo di installazione che vuole la bro dal virtuale

# --- LISTE ---
list_a : list[int] = [1, -1, 0, 1, 3, -2, 1]

# [inizio slicing : fine slicing (escluso): step]
pari = list_a[0:7:2]
print(pari)

centrali = list_a[2:5]
print(centrali)

invertito = list_a[::-1] # da inizio a fine con step -1, ovvero inverto la lista

list_b = ["ciao", "Dule", "balls"]
print(list_b)

# --- TUPLE ---
tupla_a = (1, "suca", ["parolina", "parolona", 1, 3])
print(type(tupla_a))

# --- 