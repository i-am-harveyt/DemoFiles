# 9-6
# class Restaurant(object):
#     def __init__(self, restaurant_name, cuisine_type):
#         self.restaurant_name = restaurant_name
#         self.cuisine_type = cuisine_type
    
#     def describe_restaurant(self):
#         print(
#             "Restaurant name: %s\nCuisine type: %s\n"
#             %(self.restaurant_name.capitalize(), self.cuisine_type.title())
#             )
#     def open_restaurant(self):
#         print(
#             self.restaurant_name.capitalize() +
#             " is opend!\n"
#         )

# class IceCreamStand(Restaurant):
#     def __init__(self, restaurant_name, cuisine_type, *flavors):
#         super().__init__(restaurant_name, cuisine_type)
#         self.flavors = list(flavors)
    
#     def showFlavor(self):
#         print(self.flavors)

# harveys = IceCreamStand("harvey's", 'icecream', 'strawberry', 'chocolate', 'vanilla')
# harveys.showFlavor()

# 9-7
# class User(object):
#     def __init__(self, first_name, last_name, age):
#         self.first_name = first_name
#         self.last_name = last_name
#         self.age = age
    
#     def describe_user(self):
#         print(
#             "User name: %s\n" 
#             %(self.first_name.title() + ' ' + self.last_name.title()) + 
#             "User age: %s\n" 
#             %str(self.age)
#         )

# class Admin(User):
#     def __init__(self, first_name, last_name, age, *privileges):
#         super().__init__(first_name, last_name, age)
#         self.privileges = list(privileges)
    
#     def show_privileges(self):
#         for element in self.privileges:
#             print(element.capitalize())

# harvey = Admin(
#     'harvey', 
#     'tung', 20, 
#     "can add post", "can delete post", "can ban users"
#     )
# harvey.show_privileges()

# 9-8
# class User(object):
#     def __init__(self, first_name, last_name, age):
#         self.first_name = first_name
#         self.last_name = last_name
#         self.age = age
    
#     def describe_user(self):
#         print(
#             "User name: %s\n" 
#             %(self.first_name.title() + ' ' + self.last_name.title()) + 
#             "User age: %s\n" 
#             %str(self.age)
#         )

# class Admin(User):
#     def __init__(self, first_name, last_name, age, *privileges):
#         super().__init__(first_name, last_name, age)
#         self.privileges = Privileges(privileges)
    
#     def show_privileges(self):
#         self.privileges.show_privileges()

# class Privileges(object):
#     def __init__(self, privileges):
#         self.privileges = list(privileges)

#     def show_privileges(self):
#         out = '. '.join(
#             element.capitalize() for element in self.privileges
#             ) + '.'
#         print(out)


# harvey = Admin(
#     'harvey', 
#     'tung', 20, 
#     'can delete posts', 'can add posts', 'can ban users'
#     )
# harvey.describe_user()
# harvey.privileges.show_privileges()

# 9-9
# class Car(object):
#     def __init__(self, make, model, year):
#         self.make = make
#         self.model = model
#         self.year = year
#         self.odometer_reading = 0

#     def get_descriptive_name(self):
#         long_name = str(self.year) + ' ' + self.make + ' ' + self.model
#         return long_name.title()
    
#     def read_odometer(self):
#         print("This car has " + str(self.odometer_reading) + " miles on it.")

#     def update_odometer(self, mileage):
#         if mileage >= self.odometer_reading:
#             self.odometer_reading = mileage
#         else:
#             print("You can't roll back an odometer!")
        
#     def increment_odometer(self, miles):
#         self.odometer_reading += miles

# class Battery(object):
#     def __init__(self, battery_size = 70):
#         self.battery_size = battery_size

#     def describe_battery(self):
#         print("This car has a " + str(self.battery_size) + "-kWh battery.")

#     def get_range(self):
#         if self.battery_size == 70:
#             range = 240
#         elif self.battery_size == 85:
#             range = 270

#         message = "This car can go approximately " + str(range)
#         message += "miles on a full charge."
#         print(message)

#     def upgragde_battery(self):
#         if self.battery_size != 85:
#             self.battery_size = 85

# class ElectircCar(Car):
#     def __init__(self, make, model, year):
#         super().__init__(make, model, year)
#         self.battery = Battery()
    
# myTesla = ElectircCar('tesla', 'model s', 2016)
# myTesla.battery.get_range()
# myTesla.battery.upgragde_battery()
# myTesla.battery.get_range()