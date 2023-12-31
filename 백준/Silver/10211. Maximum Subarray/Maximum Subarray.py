t = int(input())
for i in range(t):
	N = int(input())
	nums = list(map(int, input().split()))
	c = 0
	m = -9999999999999999
	for num in nums:
		c += num
		m = max(m, c)
		c = max(0, c)

	print(m)