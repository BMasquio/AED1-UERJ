import random

def somaDuplas(v, s):
  n=len(v)
  i=0
  j=n-1
  cont=0
  comparacoes=0
  duplasEncontradas = []
  comparacoes+=1
  while(i < j):
    comparacoes+=1
    if(v[i]+v[j] == s):
      cont+=1
      #duplasEncontradas.append((v[i],v[j]))
      i+=1
      j-=1
    elif(v[i]+v[j] < s):
      i+=1
    else:
      j-=1
  #print(duplasEncontradas)
  #return cont
  return comparacoes
  
def somaDuplasQuad(v, s):
  n=len(v)
  i=0
  j=n-1
  cont=0
  comparacoes=0
  for i in range(n-1):
    for j in range(i+1,n):
      comparacoes+=1
      if(v[i]+v[j] == s):
        cont+=1
  return comparacoes

#entrada do usuário
#n,s = [int(i) for i in input().split(" ")]
#v = [int(i) for i in input().split(" ")]
#print(somaDuplas(v,s))

#experimentos aleatórios
for i in range(1,6):
  n = 300*i
  s = random.randint(0, n*2)
  v = [random.randint(0, n*2) for i in range(n)]
  v.sort()
  print(n, somaDuplasQuad(v,s))