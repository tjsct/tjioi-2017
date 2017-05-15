N, M = map(int, input().split())
l = [int(input()) for _ in range(N)]

lo, hi = (max(l), sum(l))

while lo <= hi:
	mid = (lo+hi)//2
	t, r = (0, 1)
	for n in l:
		if n+t > mid:
			t = n
			r += 1
		else:
			t += n
		if r > M:
			break
	if r > M:
		lo = mid+1
	else:
		hi = mid-1
print(lo)

