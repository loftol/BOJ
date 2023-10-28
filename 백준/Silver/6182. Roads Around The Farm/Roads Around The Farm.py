n, k = map(int, input().split())

def f(n, k):
    if (n - k) % 2 == 0 and n > k:
        m = (n - k) / 2
        return f(m + k, k) + f(m, k)
    else:
        return 1

print(f(n, k))