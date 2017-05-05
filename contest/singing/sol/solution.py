#!/usr/bin/env python3

N = int(input())
for i in range(N+1):
    if i * (i+1) // 2 >= N:
        print(i)
        break
