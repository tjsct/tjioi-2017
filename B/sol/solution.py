num_array = input().split(" ")
N = int(num_array[0])
x = int(num_array[1])
y = int(num_array[2])
for i in range(N):
    line = input().split(" ")
    direction = line[0]
    steps = int(line[1])
    if direction == "N":
        y += steps
    elif direction == "S":
        y -= steps
    elif direction == "E":
        x += steps
    elif direction == "W":
        x -= steps
print(x, y)

