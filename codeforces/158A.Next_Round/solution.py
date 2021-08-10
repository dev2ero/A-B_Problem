nk = input().split(' ')
n, k = nk
n, k = int(n), int(k)

line = input().split(' ')
line = list(map(lambda x: int(x), line))

sum = 0

for i in line:
    if i >= line[k-1] and i > 0:
        sum += 1

print(sum)
