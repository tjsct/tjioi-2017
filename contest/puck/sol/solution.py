#!/usr/bin/env python3

def countPerm(perm, remaining, ind, pairs):
    ans = 0

    # base case
    if not remaining:
        if perm[0] not in pairs[perm[-1]]:
            return 1

    # recur
    for val in remaining:
        if val not in pairs[perm[ind]]:
            perm[ind+1] = val
            remaining.remove(val)

            ans += countPerm(perm, remaining, ind+1, pairs)

            perm[ind+1] = -1
            remaining.add(val)

    return ans


def main():
    N, K = map(int, input().split())

    circle = [-1 for i in range(N)]
    circle[0] = 0  # fix one element of the circle

    pairs = [[] for i in range(N)]

    for i in range(K):
        a, b = map(int, input().split())
        pairs[a].append(b)
        pairs[b].append(a)

    remaining = set(range(N))
    remaining.remove(0)
    print(countPerm(circle, remaining, 0, pairs))


if __name__ == '__main__':
    main()
