# handling special elements
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, we are out of green peppers right now")
    else:
        print("Adding " + requested_topping + ".")

print("\nFinished making your pizza!")

# ensure that a list is not empty
requested_toppings = []
if requested_toppings:  # directly using name to ensure
    for requested_topping in requested_toppings:
        print("\nAdding" + requested_toppings + ".")
else:
    print("Are you sure you want a plain pizza")

