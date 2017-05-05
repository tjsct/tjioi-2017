#!/usr/bin/env python3

N, x, y = map(int, input().split())

for i in range(N):
    line = input().split()
    direction = line[0]
    steps = int(line[1])

    if direction == "N":
        y += steps
    elif direction == "S":
        y -= steps
    elif direction == "E":
        x += steps
    elif direction == "W":
        x -= steps

print(x, y)
