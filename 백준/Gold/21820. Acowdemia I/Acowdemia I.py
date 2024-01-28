n, l = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

lo, hi = 0, 100001
# [lo, hi)

def solve(x):
    global l, n
    if(x > n):
        return False
    sum = 0
    for a in arr[-x:]:
        if a == x - 1:
            sum += 1
        elif a < x - 1:
            return False
    if sum <= l:
        return True
    else: return False

while(lo + 1 < hi):
    mid = (lo + hi) // 2
    if (solve(mid)):
        lo = mid
    else:
        hi = mid

print(lo)