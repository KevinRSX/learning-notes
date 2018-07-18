def make_pizza(size, *toppings):
    """brief about the pizza"""
    print("\nMaking a " + str(size) + "-inch pizza with the following toppings:")
    for topping in toppings:
        print("- " + topping)
