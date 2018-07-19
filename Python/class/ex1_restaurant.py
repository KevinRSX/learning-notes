# p142, 9-1, 9-2

class Restaurant():

    def __init__(self, restaurant_type, cuisine_type):
        self.restaurant_type = restaurant_type
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):
        print("Restaurant's name: " + self.restaurant_type)
        print("We cook " + self.cuisine_type + " food")

    def open_restaurant(self):
        print(self.restaurant_type + " is now open.")


k1 = Restaurant("FFF", "Chinese")
k2 = Restaurant("ONON", "Japanese")
k3 = Restaurant("DD", "Western")

k1.describe_restaurant()
k2.describe_restaurant()
k3.describe_restaurant()
