# 9-4
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
tonys = Restaurant("Tony's", "american")
tiffys = Restaurant("Tiffy's", "japanese")

