n = int(input())
acnt, bcnt = 0, 0
for _ in range(n):
    a, b = map(int, input().split())
    acnt += a
    bcnt += b

print(min(acnt, n - acnt) + min(bcnt, n - bcnt))
