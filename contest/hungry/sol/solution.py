#!/usr/bin/env python3

from heapq import *

n = int(input())
grid = [list(map(int, input().strip().split())) for i in range(n)]

pq = []
seen = [[False for j in range(n)] for i in range(n)]

heappush(pq, (grid[0][0], (0, 0)))

while pq:
    cost, loc = heappop(pq)
    if seen[loc[0]][loc[1]]:
        continue
    seen[loc[0]][loc[1]] = True

    if loc == (n-1, n-1):
        print(cost)
        break

    neighbors = [
        (loc[0] + 1, loc[1]    ),
        (loc[0]    , loc[1] + 1),
    ]
    for d in neighbors:
        if d[0] < n and d[1] < n and not seen[d[0]][d[1]]:
            d_cost = cost + grid[d[0]][d[1]]
            heappush(pq, (d_cost, d))
