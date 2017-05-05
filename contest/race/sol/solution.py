#!/usr/bin/env python3

n, T = map(int, input().split())

for _ in range(n):
    a, b = map(int, input().split())
    d = a//100 * T
    if d <= b:
        print("POTATO")
    else:
        print("SPEEDRACER")
