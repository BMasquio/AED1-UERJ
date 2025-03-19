import random

def potenciaRapida(base, expoente):
	resultado = 1

	while expoente > 0:
		if expoente % 2 == 1:
			resultado *= base
		base *= base
		expoente //= 2

	return resultado

def calcular(N):
	B = [random.randint(1, 1000) for _ in range(N)]
	t = 0
	for i in range(1, N+1):
		for j in range(1, i+1):
			t += B[j-1]
	return t

def crivoDeEratostenes(n):
    numeros = [True] * (n + 1)
    
    numeros[0] = False
    numeros[1] = False
    
    primos = []
    
    for numero, primo in enumerate(numeros):
        if primo:
            primos.append(numero)
            
            for i in range(numero * 2, n + 1, numero):
                numeros[i] = False

    return primos
