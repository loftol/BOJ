n, m = map(int, input().split())
while True:
    for i in range(1, n + 1):
        if m >= i:
            m -= i
        else:
            break
    else:
        continue
    break
print(m)
