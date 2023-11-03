n = int(input())
numbers = list(map(int, input().split()))

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

if n == 2:
    gcd_value = gcd(numbers[0], numbers[1])
else:
    gcd_value = gcd(gcd(numbers[0], numbers[1]), numbers[2])

# 최대공약수의 약수 출력
for i in range(1, gcd_value + 1):
    if gcd_value % i == 0:
        print(i)