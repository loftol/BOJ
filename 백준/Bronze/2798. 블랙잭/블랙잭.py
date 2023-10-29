n, m = map(int, input().split())
arr = list(map(int, input().split()))

answers = []
M = 0

for i in range(0, n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            val = arr[i] + arr[j] + arr[k]
            if(val <= m):
                M = max(M, val)

print(M)