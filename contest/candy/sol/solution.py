#!/usr/bin/env python3

N = int(input())

candies = {}

for i in range(N):
    line = input().split()
    name, sugar = line[0], int(line[1])
    candies[name] = sugar

receipt = input()
test_str = ''
count = 0

for c in receipt:
    test_str += c
    if test_str in candies:
        count += candies[test_str]
        test_str = ''

assert not test_str
print(count)
