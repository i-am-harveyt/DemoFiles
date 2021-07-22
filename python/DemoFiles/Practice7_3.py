# 7-8
# orders = [
#     'burger', 'cola', 'pizza'
# ]
# finished_orders = []

# while orders:
#     print("I made you a %s" %(orders[0].capitalize()))
#     finished_orders.append(orders.pop(0))

# print(orders)
# print(finished_orders)

#7-9
# orders = [
#     'burger', 'cola', 'pizza'
# ]
# finished_orders = []

# while orders:
#     if orders[0] == 'cola':
#         print("Cola is sold out!")
#         orders.remove('cola')
#     else:
#         print("I made you a %s" %(orders[0].capitalize()))
#         finished_orders.append(orders.pop(0))

# print(orders)
# print(finished_orders)

#8-0
dreamed_vacation = {}

anyone = ''
place = ''
greeting = "What's your name? If you want to quit, type 'quit'."
ans = "Ans: "
question = "Where do you want to go? If nowhere, type 'nowhere.'"
while True:
    print(greeting)
    anyone = input(ans)
    if anyone != 'quit':
        if anyone not in dreamed_vacation:
            dreamed_vacation[anyone] = []
        while True:
            print(question)
            place = input(ans)
            if place != 'nowhere':
                dreamed_vacation[anyone].append(place)
            else:
                print("\n")
                break
    else:
        print('\n')
        break

for p, values in dreamed_vacation.items():
    str = ''
    for value in values:
        if value != values[len(values)-1]:
            str += value.capitalize() + ', '
        else:
            str += value.capitalize()
    print("%s wants to go to %s." %(p.title(), str))

print("\n")