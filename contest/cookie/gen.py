#!/usr/bin/env python3

import random
import sys

import math
from functools import reduce

import prime_sieve
primes = prime_sieve.list_primes(1000000)

N = int(sys.argv[1])
Q = int(sys.argv[2])
amax = int(sys.argv[3])

assert 1 <= N <= 100000
assert 1 <= Q <= 100000
assert 1 <= amax <= 1000000

# generate array
A = [random.randrange(1, amax+1) for i in range(N)]

if N <= 1000:
    lmao = reduce(lambda a, b: a * b * math.gcd(a, b), A, 1)
    primes2 = list(filter(lambda n: lmao % n == 0, primes))
else:
    primes2 = primes


# generate queries
Q2 = int(Q / 9) if N <= 1000 else 0
Q1 = Q - Q2
queries1 = [random.choice(primes2) for i in range(Q1)]
queries2 = [random.choice(primes) for i in range(Q2)]

queries = queries1 + queries2
random.shuffle(queries)

# print stuff
print(N, Q)
print(' '.join(map(str, A)))
print('\n'.join(map(str, queries)))

print('done', file=sys.stderr)

