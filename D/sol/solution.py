line = input().split(" ")
n = int(line[0])
k = int(line[1])
array = []
[array.append(int(input())) for i in range(n)]
array = list(reversed(sorted(array)))
total = sum(array[:k])
print(total)
