#for value in range(1, 21):
#    print(value)

values = [value for value in range(1, 1000001)]
#for value in values:
#    print(value)

#print(sum(values))

odds = [value for value in range(1, 20, 2)]
#print(odds)

times = []
for x in range(1, 30):
    if(x % 3 == 0):
        times.append(x)
#print(times)

#for x in range(1, 11):
    ##print(x**3)
list = [values**3 for values in range(1, 11)]
#print(list)
print("The first three items in the list are " + str(list[:3]))
print("Three items from the middle of the list are "
     + str(list[len(list)//2-1:len(list)//2+2]))
print("The last three items in the list are " + str(list[-3:]))