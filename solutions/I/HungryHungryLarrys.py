import heapq

try:
    input = raw_input
except e:
    #thank god you're using python 3
    pass

n = int(input(""))
m = [[int(x) for x in input("").strip().split(" ")] for i in range(n)]

pq = []
heapq.heappush(pq, (m[0][0],0,0))
seen = {}
while len(pq) > 0:
    c = heapq.heappop(pq)
    if c[1:] == (n-1,n-1):
        print(c[0])
        break
    if c[1:] in seen:
        continue
    seen[c[1:]] = None
    for d in [(c[1]+1,c[2]),(c[1],c[2]+1)]:
        if d not in seen and d[0]<n and d[1]<n:
            heapq.heappush(pq, (c[0]+m[d[0]][d[1]],)+d)
