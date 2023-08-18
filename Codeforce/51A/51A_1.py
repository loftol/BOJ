from collections import Counter

str1 = input().replace(' ','')
str2 = input().replace(' ','')
print('YES' if not Counter(str2) - Counter(str1) else 'NO')
