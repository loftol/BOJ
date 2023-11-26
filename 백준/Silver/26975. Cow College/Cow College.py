from sys import stdin

input = stdin.readline

cowsNum = int(input())
cowsT = list(map(int, input().split()))
cowsT.sort()
high = 0
tuition = 0
for i in cowsT:
    cows = (len(cowsT) - cowsT.index(i)) * i
    if cows > high:
        high = cows
        tuition = i
    elif cows == high:
        if i < tuition:
            tuition = i

print(high, tuition)
