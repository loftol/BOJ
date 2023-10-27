n = int(input())
for i in range(1, n):
    str_i = str(i)
    val = i
    for u in str_i:
        val += int(u)
    if(val == n):
        print(i)
        break
else:
    print(0)