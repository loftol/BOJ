n = int(input())
x = input()
a = pow(10, n/2)
isLucky = True
 
front = back = 0
for i in range(n//2):
    if(x[i] != '4' and x[i] != '7'): isLucky = False
    front += int(x[i])
 
for i in range(n//2, n):
    if(x[i] != '4' and x[i] != '7'): isLucky = False
    back += int(x[i])
    
if(isLucky and front == back): print('YES')
else : print('NO')
