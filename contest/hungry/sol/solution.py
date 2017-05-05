#!/usr/bin/env python3

from heapq import *

n = int(input())
m = [list(map(int, input().strip().split())) for i in range(n)]

pq = []
seen = set()

heappush(pq, (m[0][0], (0, 0)))

while pq:
    cost, loc = heappop(pq)
    if loc in seen:
        continue
    seen.add(loc)

    if loc == (n-1, n-1):
        print(cost)
        break

    neighbors = [
        (loc[0] + 1, loc[1]    ),
        (loc[0]    , loc[1] + 1),
    ]
    for d in neighbors:
        if d not in seen and d[0] < n and d[1] < n:
            d_cost = cost + m[d[0]][d[1]]
            heappush(pq, (d_cost, d))
