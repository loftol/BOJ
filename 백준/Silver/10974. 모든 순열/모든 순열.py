n = int(input())

def f(depth, state:list):
    global n
    # base case
    if (depth == n):
        for i in state:
            print(i, end = " ")
        print()
        return
    # recursive part
    for i in range(1, n + 1):
        if(i not in state):
            state.append(i)
            f(depth + 1, state)
            state.pop()

f(0, [])