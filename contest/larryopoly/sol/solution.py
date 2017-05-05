#!/usr/bin/env python3

N, M = map(int, input().split())
bills = [int(input()) for _ in range(N)]
max_val = sum(bills)

# initialize dp array
dp = [-1 for _ in range(max_val + 1)]
dp[0] = 0

# process dp
for i, b in enumerate(bills):
    for j in range(max_val - b, -1, -1):
        if dp[j] != -1:
            dp[j + b] = max(dp[j] + 1, dp[j + b])

# answer queries
for _ in range(M):
    c = int(input())
    print(dp[c])
