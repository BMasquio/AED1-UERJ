from random import *

def selecao(v):
    n = len(v)
    comp = 0
    for i in range(n-1):
        indiceMenor = i
        for j in range(i,n):
            comp += 1
            if(v[j]<v[indiceMenor]):
                indiceMenor = j
        aux = v[indiceMenor]
        v[indiceMenor] = v[i]
        v[i] = aux
    return comp

def insercao(v):
    comp = 0
    n = len(v)
    for i in range(2,n):
       v[0] = v[i]
       j=i
       comp+=1
       while(v[j-1] > v[0]):
           v[j] = v[j-1]
           j = j-1
           comp+=1
       v[j] = v[0]
    return comp

#selecao
#for j in range(1,5):
#    size = 10**j
#caso aleatório(médio)
#    v = [randrange(1,1000000) for i in range(size)]
#melhor caso
#    v = [i for i in range(size)]
#    comparacoes = selecao(v)
#    print(size,comparacoes)

#insercao
for j in range(1,5):
    size = 10**j
#caso aleatório(médio)
#    v = [randrange(1,1000000) for i in range(size)]
#melhor caso
#    v = [i for i in range(size-1,-1,-1)]
#pior caso
#    v = [i for i in range(size)]
    comparacoes = insercao(v)
    print(size,comparacoes)

#insercao(v)
#print(v)
#https://sathler.github.io/Regresso-Page/