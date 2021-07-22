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
