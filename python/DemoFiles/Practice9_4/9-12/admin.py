from user import User

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