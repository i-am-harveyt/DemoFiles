# 9-1
class Restaurant(object):
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type
    
    def describe_restaurant(self):
        print(
            "Restaurant name: %s\nCuisine type: %s\n"
            %(self.restaurant_name.capitalize(), self.cuisine_type.title())
            )
    def open_restaurant(self):
        print(
            self.restaurant_name.capitalize() +
            " is opend!\n"
        )
harveys = Restaurant("Harvey's", 'chinese')
harveys.describe_restaurant()
harveys.open_restaurant()

tonys = Restaurant("Tony's", "american")
tonys.describe_restaurant()

tiffys = Restaurant("Tiffy's", "japanese")
tiffys.describe_restaurant()


# 9-3
class User(object):
    def __init__(self, first_name, last_name, age):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
    
    def describe_user(self):
        print(
            "User name: %s\n" 
            %(self.first_name.title() + ' ' + self.last_name.title()) + 
            "User age: %s\n" 
            %str(self.age)
        )

harvey = User("harvey", "tung", 20)
tiffy = User("tiffany", "chou", 20)
tony = User("tony", "tung", 22)

harvey.describe_user()
tiffy.describe_user()
tony.describe_user()