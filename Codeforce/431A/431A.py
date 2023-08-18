arr = list(map(int, input().split()))
inp = input()
sum = 0
for c in inp: sum += arr[int(c) - 1]
print(sum)
