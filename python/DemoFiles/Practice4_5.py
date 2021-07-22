cafeteria = ('pizza', 'coffee', 'coke', 'donut', 'burger')

newMenu = ['hotdogs']
for x in range(1, len(cafeteria)):
    newMenu.append(cafeteria[x])

newMenu = tuple(newMenu)

#print(newMenu)

for x in newMenu:
    print(x, end = ' ')
#print('\n')