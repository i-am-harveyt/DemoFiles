people = {
    'aeistein': {
        'first': 'albert', 
        'last': 'einstein', 
        'location': 'princeton'
    }, 
    'mcurie': {
        'first': 'marie', 
        'last': 'curie', 
        'location': 'paris'
    }, 
    'ppicaso':{
        'first': 'pablo', 
        'last': 'picaso', 
        'location': 'spain'
    }, 
    'wsun':{
        'first': 'wen', 
        'last': 'sun', 
        'location': 'hawaii'
    }
}
for person, person_info in people.items():
    print(
        "Name: %s %s\n"
        %(person_info['first'].title(), person_info['last'].title()) + 
        "Location: %s\n"
        %(person_info['location'].title())
        )

pets = {
    'edward': {
        'species': 'dog', 
        'owner': 'eric'
    },
    'ethen': {
        'species': 'fish', 
        'owner': 'John'
    }, 
    'sherry': {
        'species': 'cat', 
        'owner': 'Kate'
    }
}

for pet, pet_info in pets.items():
    print(
        "Name: %s\n"
        %(pet.title()) + 
        "Species: %s\n"
        %(pet_info['species'].title()) + 
        "Owner: %s\n"
        %(pet_info['owner'].title()
        )
    )

favorite_place = {
    'albert':[
        'puli', 'yilan', 'japan'
    ], 
    'grace':[
        'tongluo', 'taipei', 'korea'
    ], 
    'tony':[
        'taipei', 'puli', 'japan'
    ], 
    'harvey':[
        'taipei', 'japan', 'hong kong'
    ]
}

for person, places in favorite_place.items():
    string = ''
    for place in places:
        if place == places[len(places)-1]:
            string += place.title()
        else:
            string += place.title() + ', '
    print(
        "Name: %s\n" %person.title() + 
        "Place: " + string
    )

print('\n')

favorite_numbers = {
    'tiffany':[
        1, 21, 8, 22.5
    ], 
    'harvey':[
        21, 8, 28, 22.5
    ], 
    'tony':[
        6, 18
    ], 
    'gigi':[
        11, 15
    ]
}

for person, num in favorite_numbers.items():
    nums = ' '
    for number in num:
        if number == num[len(num)-1]:
            nums += str(number)
        else:
            nums += str(number) + ' '
    print("%s's favorite number(s): %s" %(person.title(), nums))

