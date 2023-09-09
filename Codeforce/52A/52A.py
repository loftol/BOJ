from collections import Counter

n = int(input())
_, a = Counter(input().split()).most_common(1)[0]
print(n - a)
