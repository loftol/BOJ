tc = int(input())
for _ in range(tc):
    l = int(input())
    inp = input()
    S = set(inp)
    cnt = 1
    for i in range(1, l):
        if inp[i] != inp[i - 1]: cnt += 1
    print('YES' if len(S) == cnt else 'NO')
