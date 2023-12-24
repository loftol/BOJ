n = int(input())

times = [0] * 1000005
for i in range(n):
    s, e = map(int, input().split())
    times[s] += 1
    times[e + 1] += -1

for i in range(1, len(times)):
    times[i] += times[i - 1]

_ = input()

query = list(map(int, input().split()))
for q in query:
    print(times[q])