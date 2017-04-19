N = int(input())
for i in range(N):
  if i*(i+1)//2 >= N:
    print(i)
    break
