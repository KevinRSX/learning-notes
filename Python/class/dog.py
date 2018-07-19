class Dog():
    """simulate a pet dog"""

    def __init__(self, name, age):
        """initialize a dog's properties"""
        self.name = name
        self.age = age

    def sit(self):
        """sit order"""
        print(self.name.title() + " is now sitting.")

    def roll_over(self):
        """roll over order"""
        print(self.name.title() + " roll over!")


my_dog = Dog('willie', 6)

print("My dog's name is " + my_dog.name.title() + ".")
print("My dog is " + str(my_dog.age) + " years old.")
my_dog.sit()
my_dog.roll_over()
