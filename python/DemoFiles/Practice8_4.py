# 8-9
# magicians = ['harvey', 'tiffany', 'tony']

# def show_magicians(magicians):
#     for magician in magicians:
#         print(magician.capitalize())

# show_magicians(magicians)

# 8-10
# magicians = ['harvey', 'tiffany', 'tony']

# def show_magicians(magicians):
#     for magician in magicians:
#         magician = make_great(magician)
#         print(magician.title())

# def make_great(name):
#     return "The great " + name

# show_magicians(magicians)

# 8-11
magicians = ['harvey', 'tiffany', 'tony']

def show_magicians(magicians):
    for magician in magicians:
        magician = make_great(magician)
        print(magician.title())

def make_great(name):
    return "The great " + name

show_magicians(magicians[:])

for magician in magicians:
    print(magician.title())


