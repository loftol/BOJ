n, m =  map(int, input().split())
while(True):
    n += 1
    for i in range(2, n):
        if n % i == 0:
            break
    else:
        break
print('YES' if n == m else 'NO')
