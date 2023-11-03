n, m = map(int, input().split())

def f(depth, prev, arr):
    global n, m
    if(depth == m):
        for i in arr:
            print(i, end=" ")
        print()
        return
    for i in range(prev + 1, n + 1):
        arr.append(i)
        f(depth + 1, i, arr)
        arr.pop()

f(0, 0, [])