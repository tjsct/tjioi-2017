#!/usr/bin/env python3

import random
import sys

N = int(sys.argv[1])
cmax = int(sys.argv[2])
assert 1 <= N <= 1000000
assert 0 <= cmax <= 2**30-1

x = random.randint(-cmax, cmax)
y = random.randint(-cmax, cmax)

print(N, x, y)

for i in range(N):
    if random.randrange(1) == 0:
        dx = random.randint(-cmax, cmax) - x
        print(('E' if dx > 0 else 'W'), abs(dx))
        x += dx
    else:
        dy = random.randint(-cmax, cmax) - y
        print(('N' if dy > 0 else 'S'), abs(dy))
        y += dy

