n = int(input())
arr = []
for i in range(n):
    x, y = list(map(int, input().split()))
    arr.append([x, y])

for x, y in arr:
    cnt = 0
    for x1, y1 in arr:
        if(x1 > x and y1 > y) : cnt+=1
    print(cnt + 1, end=' ')
