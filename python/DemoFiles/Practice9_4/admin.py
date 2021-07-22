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

class Admin(User):
    def __init__(self, first_name, last_name, age, *privileges):
        super().__init__(first_name, last_name, age)
        self.privileges = Privileges(privileges)
    
    def show_privileges(self):
        self.privileges.show_privileges()

class Privileges(object):
    def __init__(self, privileges):
        self.privileges = list(privileges)

    def show_privileges(self):
        out = '. '.join(
            element.capitalize() for element in self.privileges
            ) + '.'
        print(out)