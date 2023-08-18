n = int(input())
mp = {}
for _ in range(n):
    x, d = map(int, input().split())
    mp[x] = x + d
for x, y in mp.items():
    if y not in mp : continue
    if mp[x] == y and mp[y] == x:
        print('YES')
        break
else:
    print('NO')
