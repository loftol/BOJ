n = int(input())

def f(x):
    if x < 0: return 0
    return (x // 7) * 2 + min(2, x % 7)

print(f(n-5), f(n))
