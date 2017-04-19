n, T = map(int, input().split())
for _ in range(n):
  a, b = map(int, input().split())
  d = a//100 * T
  if d <= b:
    print("Once you quit track you can never come back")
  else:
    print("What do you mean I'm slow?")
