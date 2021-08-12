for i in range(5):
    l = input().replace(' ', '')
    if l.find('1') != -1:
        ans = abs(i-2) + abs(l.find('1')-2)
print(ans)
