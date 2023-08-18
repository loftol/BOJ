def solve():
    str1 = input().replace(' ','')
    str2 = input().replace(' ','')
    cnt = {}
    for c in str1:
        if c not in cnt : cnt[c] = 1
        else cnt[c] += 1
    for c in str2:
        if c not in cnt or cnt[c] == 0 :
            print("NO\n")
            return
        else:
            cnt[ord(c)] -= 1
    print("YES\n")
    return
 
solve()
