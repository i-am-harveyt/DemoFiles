alien_color = 'yellow'

if alien_color == 'green':
    print("You got 5 points!")
elif alien_color == 'yellow':
    print("You got 10 points!")
else:
    print("You got 15 points!")

age = 20

if age < 2:
    print("He is a baby.")
elif 2 <= age and age < 4:
    print("He is toddling.")
elif 4 <= age and age < 13:
    print("He is a child.")
elif 13 <= age and age <  20:
    print("He is a teenager.")
elif 20 <= age and age < 65:
    print("He is an adult.")
else:
    print("He is a senior citizen.")

favorite_fruits = ['apple', 'banana', 'orange']

if 'apple' in favorite_fruits:
    print("You really like apples!")
if 'banana' in favorite_fruits:
    print("You really like bananas!")
if 'guava' in favorite_fruits:
    print("You really like guavas!")
if 'grape' in favorite_fruits:
    print("You really like grapes!")
if 'orange' in favorite_fruits:
    print("You really like oranges!")
