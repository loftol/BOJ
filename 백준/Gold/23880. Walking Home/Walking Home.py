dx = [1, 0]
dy = [0, 1]
n, k = 0, 0
board = []

def recursive(i, j, d, cnt):
	ret = 0
	if i == n - 1 and j == n - 1:
		return 1
	ni = i + dx[d]
	nj = j + dy[d]
	if ni < n and nj < n and board[ni][nj] == '.':
		ret += recursive(ni, nj, d, cnt)

	if cnt < k:
		d = 1 - d
		ni = i + dx[d]
		nj = j + dy[d]
		if ni < n and nj < n and board[ni][nj] == '.':
			ret += recursive(ni, nj, d, cnt + 1)

	return ret
	
def solve():
	global n, k, board, ans
	n, k = map(int, input().split())
	board = [input() for _ in range(n)]
	ans = 0
	if board[1][0] == '.':
		ans += recursive(1, 0, 0, 0)
	if board[0][1] == '.':
		ans += recursive(0, 1, 1, 0)
	print(ans)

	

tc = int(input())
for _ in range(tc):
	solve()