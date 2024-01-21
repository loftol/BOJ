def solve():
	n = int(input())
	yearList = ["Ox","Tiger","Rabbit","Dragon","Snake","Horse","Goat","Monkey","Rooster","Dog","Pig","Rat"]
	yearDict = {}
	idx = 0
	for name in yearList:
		yearDict[name] = idx
		idx += 1

	cowDict = {"Bessie":0}
	for i in range(n):
		a, _born, _in, pn, b, _year, _from, c = input().split()
		if(pn == "previous") : pn = -1
		else : pn = 1
  
		x = cowDict[c]
		x += pn
		while(x % 12 != yearDict[b]):
			x += pn

		cowDict[a] = x
	
	print(abs(cowDict["Elsie"]))

tc = 1
#tc = int(input())

for _ in range(tc):
	solve()