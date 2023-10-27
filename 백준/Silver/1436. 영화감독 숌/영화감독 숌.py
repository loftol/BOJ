n = int(input())

for i in range(1, 7000000):
    str_i = str(i)
    if("666" in str_i):
        n -= 1
    if(not n):
        print(i)
        break
