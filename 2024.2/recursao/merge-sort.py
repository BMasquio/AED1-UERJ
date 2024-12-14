import random

def mergeSort(e,d,v):
  #print('mergeSort(',e,',',d,')')
  if(e != d):
    i=(e+d)//2
    mergeSort(e,i,v)
    mergeSort(i+1,d,v)
    mergeSegmentos(e,i,d,v)

def mergeSegmentos(e,i,d,v):
  v2 = [0]*(d-e+1)
  p1 = e
  p2 = i+1
  p3 = 0
  while(p1 < i+1 and p2 < d+1):
    if(v[p1] < v[p2]):
      v2[p3] = v[p1]
      p1 = p1+1
      p3 = p3+1
    else:
      v2[p3] = v[p2]
      p2 = p2+1
      p3 = p3+1
  while(p1 < i+1):
    v2[p3] = v[p1]
    p1 = p1+1
    p3 = p3+1
  while(p2 < d+1):
    v2[p3] = v[p2]
    p2 = p2+1
    p3 = p3+1
  #print(v2)
  for i in range(len(v2)):
    v[e+i] = v2[i]

size = 20
v = [random.randrange(0, 100) for i in range(size)]
print(v)
mergeSort(0,len(v)-1,v)
print(v)
