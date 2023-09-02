from collections import Counter
 
n = int(input())
arr = Counter(input().split())
ans = 0
for val, cnt in arr.items():
    if cnt == 2 and val != '0': 
        ans += 1
    if cnt > 2 and val != '0':
        ans = -1
        break
 
print(ans)
