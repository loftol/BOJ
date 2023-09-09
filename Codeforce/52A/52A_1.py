n = int(input())
ans = [0] * 4
arr = list(map(int, input().split()))
for a in arr:
    ans[a] += 1

print(n - max(ans))
