def fatorial(p):
    print(f'Encontrando fatorial de {p}')
    if(p == 0):
        return 1
    else:
        fatorialAnterior = fatorial(p-1)
        print(f'Terminei de calcular fatorial({p-1})')
        return p*fatorialAnterior

print(fatorial(4))
