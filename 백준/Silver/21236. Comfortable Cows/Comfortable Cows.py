def solve():
	cnt = [[-1] * 1001 for i in range(1001)]
	dx = [0, 1, 0, -1]
	dy = [1, 0, -1, 0]
	n = int(input())
	ans = 0
 
	for i in range(n):
		x, y = map(int, input().split())
		cnt[x][y] = 0
		for dir in range(4):
			nx = x + dx[dir]
			ny = y + dy[dir]
			if(nx >= 0 and nx <= 1000 and ny >= 0 and ny <= 1000):
				if(cnt[nx][ny] >= 0):
					cnt[nx][ny] += 1
					cnt[x][y] += 1
					if(cnt[nx][ny] == 3):
						ans += 1
					elif(cnt[nx][ny] == 4):
						ans -= 1
			if(cnt[x][y] == 3): ans += 1
		print(ans)	

solve()