n = input()
m = len(n)

for i in range(1, m): # 뒤쪽 문자열의 가장 앞 인덱스가 i입니다.
    fr = n[:i]
    bk = n[i:]
    val1, val2 = 1, 1
    for c in fr:
        val1 *= int(c)
    for c in bk:
        val2 *= int(c)
    if(val1 == val2):
        print("YES")
        break
else:
    print("NO")