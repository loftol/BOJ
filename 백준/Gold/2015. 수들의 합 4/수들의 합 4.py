import sys
from collections import defaultdict

input = sys.stdin.readline
n, k = map(int,input().split())

arr = list(map(int, input().split()))

psum = defaultdict(int)
total, ans = 0, 0
psum[0]+=1
for j in range(0, n):
    total += arr[j]
    ans += psum[total - k]
    psum[total]+=1

print(ans)
	