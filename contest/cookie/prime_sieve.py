
# Returns a list of all prime numbers less than N
def list_primes(N):
    if N <= 0:
        raise ValueError('%d is out of bounds' % N)
    elif N <= 2:
        return []

    is_prime = [True] * N

    # even numbers are not prime
    for i in range(0, N, 2):
        is_prime[i] = False

    # exceptions
    is_prime[0] = False
    is_prime[1] = False
    is_prime[2] = True

    i = 3
    while i**2 <= N:
        if is_prime[i]:
            # multiples of a prime number are not prime
            # start at i**2 because i*(i-2) is already marked by i-2
            # increment by 2*i because i*(i+1) is even
            for j in range(i**2, N, 2*i):
                is_prime[j] = False
        i += 2

    # make list of primes from bool array
    return [i for i in range(2, N) if is_prime[i]]
