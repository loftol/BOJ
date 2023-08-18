arr = [1400, 1600, 1900, 5001]      
tc = int(input())
for _ in range(tc):
    inp = int(input())
    for i in range(4):
        if arr[i] > inp:
            print(f'Division {4 - i}')
            break
