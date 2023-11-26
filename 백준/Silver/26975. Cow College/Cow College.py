from sys import stdin

cowsNum = int(stdin.readline().strip())
cowsT = list(map(int, stdin.readline().strip().split()))
cowsT.sort()
high = 0
tuition = 0
for i in range(len(cowsT)):
    val = cowsT[i]
    cows = (len(cowsT) - i) * val
    if cows > high:
        high = cows
        tuition = val
    elif cows == high:
        if val < tuition:
            tuition = val

print(high, tuition)
