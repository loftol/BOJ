n = int(input())

cnt = 0

for i in range(1, n + 1):
    st = str(i)
    for c in st:
        if (c == '3') or (c == '6') or (c == '9'):
            cnt += 1
       
       
print(cnt)