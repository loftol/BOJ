def f(n, fr, to):
    if(n == 0): return
    x = -1
    arr = [fr, to]
    if(1 not in arr) : x = 1
    elif(2 not in arr) : x = 2
    elif(3 not in arr) : x = 3
    f(n - 1, fr, x)
    print(fr, to)
    f(n-1, x, to)
n = int(input())
print(2 ** n - 1)
if(n <= 20) :
    f(n, 1, 3)