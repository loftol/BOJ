n = int(input())
target = list(map(int, input().split()))
start = list(map(int, input().split()))
arr = [target[i] - start[i] for i in range(n)]
arr.append(0)
last = 0
ans = 0
for i in arr:
    if last * i > 0:
        if abs(i) > abs(last):
            last = i
        elif abs(i) < abs(last):
            ans += abs(last - i)
            last = i
    else:
        ans += abs(last)
        last = i


print(ans)
