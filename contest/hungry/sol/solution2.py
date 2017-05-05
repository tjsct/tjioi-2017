#!/usr/bin/env python3

N = int(input())
grid = [list(map(int, input().strip().split())) for i in range(N)]

dp = [[N * N * 10 for _ in range(N)] for _ in range(N)]
dp[0][0] = 0

for i in range(N):
    for j in range(N):
        if i > 0:
            dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j])
        if j > 0:
            dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j])

print(dp[N-1][N-1])
