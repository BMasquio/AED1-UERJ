def mult(b, k):
  b2 = 200*[0]
  #...
  return b2

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
  n2 = int(arr[1])
  #print(int(arr[0])*int(arr[1]))
  print(mult(n1,n2))
  
  
'''
Entrada:
4
422984387293847234987983247239847 47
22220492049 -5
-4983484982349 8797
9999999999999 999

Saída:
19880266202810820044435212620272809
111102460245
43839717389724153
9989999999999001
'''
