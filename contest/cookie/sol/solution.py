_, q = map(int, input().split())
l = list(map(int, input().split()))
d = [-1] * 1000005
for (i, n) in enumerate(l):
	if n % 2 == 0:
		if d[2] == -1:
			d[2] = i
		while n % 2 == 0:
			n //= 2
	j = 3
	while j * j <= n:
		if n % j == 0:
			if d[j] == -1:
				d[j] = i
			while n % j == 0:
				n //= j
		j += 2
	if n != 1:
		if d[n] == -1:
			d[n] = i
for _ in range(q):
	x = int(input())
	if d[x] != -1:
		print(d[x]+1)
	else:
		print(-1)
