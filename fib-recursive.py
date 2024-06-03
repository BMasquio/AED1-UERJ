# fib(i) = fib(i-1) + fib(i-2)
# 1 1 2 3 5 8 13 ...

def fib(i):
    print(f'fib({i})')
    #caso base (não pode ter recursão)
    if(i <= 2):
        return 1
    #caso geral (vai ter a recursão)
    return fib(i-1)+fib(i-2)

i=5
print(f'fib({i}) = {fib(i)}')
