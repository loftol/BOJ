rook = input()
knight = input()
ans = 0
for i in range(ord('a'), ord('h') + 1):
    c = chr(i)
    if rook[0] == c: continue
    for j in range(1, 9):
        if int(rook[1]) == j: continue
        rx = ord(rook[0])
        ry = int(rook[1])
        kx = ord(knight[0])
        ky = int(knight[1])
        if(kx != i and ky != j and abs(i - kx) + abs(j - ky) == 3):
            continue
        if(kx == i and ky == j):
            continue
        if(abs(i - rx) + abs(j - ry) == 3):
            continue
        ans += 1
print(ans)
