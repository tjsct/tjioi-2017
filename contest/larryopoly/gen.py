import random
import sys

N = int(sys.argv[1])
M = int(sys.argv[2])
max_bill = int(sys.argv[3])

assert N <= 100
assert M <= 100000
assert max_bill <= 1000
assert N <= max_bill

print(N, M)

bills = random.sample(range(1, max_bill+1), N)
sum_bills = sum(bills)

for b in bills:
    print(b)

for _ in range(M // 2):
    print(sum(random.sample(bills, random.randrange(1, N+1))))

for _ in range(M - (M // 2)):
    print(random.randrange(1, sum_bills + 1))

