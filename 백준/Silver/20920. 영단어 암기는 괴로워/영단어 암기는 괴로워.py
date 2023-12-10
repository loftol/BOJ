from collections import Counter

n, m = map(int, input().split())
arr = []
for i in range(n):
    st = input()
    arr.append(st)

counter = Counter(arr)
counter = list(counter.items())

counter.sort(key = lambda x : x[0])
counter.sort(key = lambda x : len(x[0]), reverse=True)
counter.sort(key = lambda x : x[1], reverse=True)

for st, cnt in counter:
    if(len(st) < m) : continue
    print(st)
    