strin = input()

AB, BA = [], []

for i in range(len(strin) - 1) :
    if strin[i:i+2] == 'AB' :
        AB.append(i)
    elif strin[i:i+2] == 'BA' :
        BA.append(i)
    else :
        continue

if AB != [] and BA != [] and ( abs(AB[0] - BA[-1]) > 1 or abs(BA[0] - AB[-1]) > 1 ) :
    print('YES')
else :
    print('NO')
