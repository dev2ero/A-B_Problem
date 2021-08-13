import collections

names = collections.defaultdict(int)

loop = int(input())
for _ in range(loop) :
    name = input()
    if name not in names:
        names[name] += 1
        print('OK')
    else :
        print(name + str(names[name]))
        names[name] += 1
