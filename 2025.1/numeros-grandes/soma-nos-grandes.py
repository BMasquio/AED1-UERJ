def soma(b1, b2):
  b3 = 200*[0]
  #...
  return b3

def convertStrToBigNumber(s):
  b=40*[0]
  for i in range(1,len(s)):
    b[-i]=int(s[-i])
  if(s[0]=='-'):
    b[0]=-1
  else:
    b[-i-2]=int(s[0])
    b[0]=1
  return b

t = int(input())
for titeration in range(t):
  arr = input().split()
  n1 = convertStrToBigNumber(arr[0])
  n2 = convertStrToBigNumber(arr[1])
  #print(int(arr[0])+int(arr[1]))
  print(soma(n1,n2))
  
  
'''
Entrada:
4
422984387293847234987983247239847 472411244212424
22220492049 521414224142421
4983484982349 8797124124412
9999999999999 99941212442124124

Saída:
422984387293847235460394491452271
521436444634470
13780609106761
99951212442124123
'''
