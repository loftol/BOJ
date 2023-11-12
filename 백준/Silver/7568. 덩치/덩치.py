n = int(input())
weight = []
height = []

for i in range(n):
    w, h = map(int, input().split())
    weight.append(w)
    height.append(h)

for i in range(n): # fix
    rank = 1
    for j in range(n): # compare
        if(weight[j] > weight[i] and height[j] > height[i]):
            rank += 1
    print(rank, end = ' ')