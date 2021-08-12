n, l = input().split()
points = list(map(int, input().split()))

points.sort()
max_dis = 0
for i in range(1, len(points)) :
    max_dis = max(max_dis, points[i] - points[i-1])
max_dis = max(max_dis, points[0] * 2, (int(l) - points.pop()) * 2)

print(format(max_dis/2, ".10f"))
