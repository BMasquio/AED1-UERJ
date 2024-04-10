n = int(input())
lista = {}
for i in range(0,n):
    lista[input()] = True
print(f'Falta(m) {151-len(lista)} pomekon(s).')
