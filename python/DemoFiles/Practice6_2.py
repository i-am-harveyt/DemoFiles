person = {
    'Last Name': 'Harvey', 
    'First Name':'Tung', 
    'Age': 20, 
    'City': 'Taipei'
    }
print(
    person['Last Name'] + 
    person['First Name'] + " Age:" + str(person['Age']) + 
    " Living in " + person['City'])
number = {
    'Harvey': 8, 
    'Tony': 18, 
    'Tiffany': 21, 
    'Gigi': 15, 
    'Melody': 26
    }
for k, v in number.items():
    print(k + " " + str(v))

print('\n')

dictionary = {
    'var':'Variable', 
    'list':'Array in python', 
    'tuple':"I'm not very sure what it is but it's kinda strange thing", 
    'dictionary': "You're map, right?", 
    'for': 'For loop , haha'}

for k, v in dictionary.items():
    print(k + ':' + v)