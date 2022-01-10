raw = input()

output = ""

for i in raw :
    if i not in "AOYEUIaoyeui" :
        output += f'.{i.lower()}'

print(output)
