myFavoriteBrand = ['toyota', 'lexus', 'benz']
broFavoriteBrand = myFavoriteBrand[:]

myFavoriteBrand.append('volvo')
broFavoriteBrand.append('mini cooper')

print("My favorite car brands are:")
for items in myFavoriteBrand:
    print(items , end = ' ')
print('\n')
print("While my brother's favorite car brands are:")
for items in broFavoriteBrand:
    print(items, end = ' ')