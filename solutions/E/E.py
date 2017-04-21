N,K = map(int, input().split())

circle = [-1 for i in range(N)]
circle[0] = 0 # fix one element for circle

pairs = [[] for i in range(N)]
remaining = set(range(1,N))

for i in range(K):
    a,b = map(int, input().split())
    pairs[a].append(b)
    pairs[b].append(a)

ans = 0

def genPerm(perm,left,ind):
    global ans
    if len(left) == 0: #base case
        ans += checkPerm(perm,ind)
        return
    for i in left: #recur
        perm[ind+1] = i
        left.remove(i)
        if checkPerm(perm,ind) == 1:
            genPerm(perm,left,ind+1)
        left.add(i)
        perm[ind+1] = -1

def checkPerm(perm,length):
    for i in range(N):
        nextInd = i+1
        if nextInd >= N:
            nextInd = 0
        if perm[nextInd] in pairs[perm[i]]:
            return 0
        return 1

genPerm(circle,remaining,0)
print(ans)
