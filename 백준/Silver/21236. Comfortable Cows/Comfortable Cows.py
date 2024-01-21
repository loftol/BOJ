def solve():
	board = [[0] * 1001 for i in range(1001)]
	cnt = [[0] * 1001 for i in range(1001)]
	dx = [0, 1, 0, -1]
	dy = [1, 0, -1, 0]
	n = int(input())
 
	lst = []
	ans = 0
 
	for i in range(n):
		x, y = map(int, input().split())
		board[x][y] = 1
		lst.append((x, y))
		hcnt = 0
		for dir in range(4):
			nx = x + dx[dir]
			ny = y + dy[dir]
			if(nx >= 0 and nx <= 1000 and ny >= 0 and ny <= 1000):
				if(board[nx][ny]):
					cnt[nx][ny] += 1
					cnt[x][y] += 1
					if(cnt[nx][ny] == 3):
						ans += 1
					elif(cnt[nx][ny] == 4):
						ans -= 1
			if(cnt[x][y] == 3): ans += 1
		print(ans)
		

	

solve()