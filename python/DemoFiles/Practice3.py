guests = ['Tiffany', 'Justin', 'Gigi', 'Melody', 'Monica', 'Angela']

for guest in guests:
    print("Hi, "+ guest)

print('\n')
print("So sad that " + guests[len(guests)-1] + " cannot attend to this party.")
guests[len(guests)-1] = 'Lily'
print('\n')

for guest in guests:
    print("Hi, "+ guest)

print('\n')

guests.insert(0, 'Bill')
guests.insert(len(guests)//2, 'Ruby')
guests.append('Jason')

for guest in guests:
    print("Hi, "+ guest)

print('\n')
print("So sorry that due to the accident, I can only invite two guests to this party.\n")

while len(guests) > 2 :
    print("Sorry my dear " + guests.pop() + 
    ", due to the accident, I am sadly telling you that I cannot invite you to this party this time. I'll hold another party around the end of this month, see you later!")

for x in range(len(guests)):
    print("Hi, "+ guests[x] + ". I'm glad that you are still in the guest list. See you next Saturday night!")

print('\n')

for x in range(len(guests)):
    del(guests[0])
print("The length of guests list: " + str(len(guests)))

