def f(n):
    if(n == 0): 
        print("-", end="")
        return
    f(n - 1)
    print(" " * (3 ** (n - 1)), end="")
    f(n - 1)

while True:
    try:
        n = int(input())
        f(n)
        print()
    except EOFError:
        break