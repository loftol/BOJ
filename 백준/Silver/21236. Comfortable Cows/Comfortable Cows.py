import sys
input = sys.stdin.readline

cnt = [[-1] * 1001 for i in range(1001)]
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
n = int(input())
ans = 0

for i in range(n):
	x, y = map(int, input().split())
	hcnt = 0
	for dir in range(4):
		nx = x + dx[dir]
		ny = y + dy[dir]
		if(nx >= 0 and nx <= 1000 and ny >= 0 and ny <= 1000):
			ncnt = cnt[nx][ny]
			if(ncnt >= 0):
				ncnt += 1
				hcnt += 1
				if(ncnt == 3):
					ans += 1
				elif(ncnt == 4):
					ans -= 1
			cnt[nx][ny] = ncnt
	if(hcnt == 3): ans += 1
	cnt[x][y] = hcnt
	print(ans)	
