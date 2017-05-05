#!/usr/bin/env python3

n, k = map(int, input().split(" "))
array = [int(input()) for i in range(n)]
array.sort(reverse=True)
total = sum(array[:k])
print(total)
