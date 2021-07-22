# 8-6
# def city_country(city, country):
#     return city.title() + ', ' + country

# print(city_country("new york", "The US"))
# print(city_country("london", "The UK"))
# print(city_country("tokyo", "Japan"))

# 8-7
def make_album(singer, album_name):
    return {'singer': singer, 'album_name': album_name}

# album_dict = {}

# album_dict['harvey'] = make_album("harvey", "a")
# album_dict['tiffany'] = make_album("tiffany", "b")
# album_dict['tony'] = make_album("tony", "c")

# for s, a in album_dict.items():
#     print("Name: " + s.capitalize() + ". Album(s): " + a['album_name'] + '.')

# 8-8
def make_album(singer, album_name, num_of_songs = 1):
    return {
        'singer': singer, 
        'album_name': album_name, 
        'num_of_songs' : num_of_songs
        }

album_dict = {}
input_str = ''
string = "Type in the name of the singer, this engine will tell you the informations!"
ques = "The name of the singer is?(type 'quit' to exit) "
album_dict['harvey'] = make_album("harvey", "a")
album_dict['tiffany'] = make_album("tiffany", "b")
album_dict['tony'] = make_album("tony", "c")
while True:
    print(string)
    input_str = input(ques)
    if input_str == 'quit':
        break
    if input_str in album_dict:
        print(
            "\nSinger name:" + input_str.capitalize() + 
            '.\nAlbum name: ' + album_dict[input_str]['album_name'] +
            '.\nNum of songs: ' + str(album_dict[input_str]['num_of_songs'])
        )
        print('\n')
    else:
        print("Not found.\n")