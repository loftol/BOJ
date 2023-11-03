n, m = map(int, input().split())

def f(depth, arr):
    global n, m
    if(depth == m):
        for i in arr: # 탐색 구조상 arr는 이미 항상 정렬되어 있습니다.(why?)
            print(i, end=" ")
        print()
        return
    prev = arr[-1] if len(arr) else 0
    for i in range(prev + 1, n + 1): #
        arr.append(i)
        f(depth + 1, arr)
        arr.pop()

f(0, [])