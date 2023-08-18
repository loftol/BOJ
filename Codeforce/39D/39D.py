x1, y1, z1 = map(int, input().split())
x2, y2, z2 = map(int, input().split())

if(abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2) == 3):
    print('NO')
else:
    print('YES')
