def solve():
    str1 = input().replace(' ','')
    str2 = input().replace(' ','')
    for c in str2:
        if str1.count(c) < str2.count(c):
            print("NO\n")
            return
    print("YES\n")
    return

solve()
