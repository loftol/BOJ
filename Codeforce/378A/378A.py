a, b = map(int, input().split())
f = d = s = 0
for x in range(1, 7):
    if abs(a - x) < abs(b - x):
        f += 1
    elif abs(a - x) == abs(b - x):
        d += 1
    elif abs(a - x) > abs(b - x):
        s += 1        
print(f, d, s)
