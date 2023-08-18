tc = int(input())
for _ in range(tc):
    l = int(input())
    arr = list(map(int, input().split()))
    print(max(arr) - min(arr))
