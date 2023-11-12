def is_perfect_square(num):
    sqrt_num = int(num**0.5)
    return sqrt_num**2 == num

def find_perfect_squares_sum_and_min(m, n):
    perfect_squares = [x for x in range(m, n+1) if is_perfect_square(x)]
    
    if not perfect_squares:
        return -1, -1
    
    perfect_squares_sum = sum(perfect_squares)
    min_perfect_square = min(perfect_squares)
    
    return perfect_squares_sum, min_perfect_square

M = int(input())
N = int(input())
    
result_sum, result_min = find_perfect_squares_sum_and_min(M, N)

if result_sum == -1 : print(-1)
else :
    print(result_sum)
    print(result_min)