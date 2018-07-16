def greet(name):
    """show greeting on screen"""
    print("Hello! " + name)
greet('Jenny')

def describe_pet(pet_name, animal_type = 'dog', loveit = 'yes'):
    """display information about the pet"""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")
    print(loveit)
describe_pet('hamster', 'harry')
describe_pet('dog', 'willie')
describe_pet(animal_type = 'hamster', pet_name = 'harry')
describe_pet('willie', 'cat', 'true')
describe_pet(pet_name = 'harry', loveit = 'of course')
