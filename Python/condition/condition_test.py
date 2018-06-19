# note the indentation and the colon
cars = ['audi', 'bmw', 'subaru', 'toyota']

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())

# in python, compound condition is linked by and/or
if cars[0] == 'audi' and cars[1] == 'audi':
    print("yes")
else:
    print("no")

if cars[0] == 'audi' or cars[1] == 'audi':
    print("yes")
else:
    print("no")

print("\n")

# keyword in is used to check if a word is in the list
requested_toppings = ['mushrooms', 'onions', 'pineapple']
print('mushrooms' in requested_toppings)
print('pepperoni' in requested_toppings)

print('mushrooms' not in requested_toppings)