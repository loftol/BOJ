n, k = map(int, input().split())
arr = sorted(list(map(int, input().split())), reverse = True)
if n >= k :
    print(arr[k - 1], 0)
else:
    print(-1)
