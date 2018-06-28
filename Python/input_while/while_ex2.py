# p113
# 7-8
sandwich_orders = ['tuna', 'salmon', 'chicken']
finished_sandwiches = []
while sandwich_orders:
    finished_sandwiches.append(sandwich_orders.pop())
    print("Your " + finished_sandwiches[len(finished_sandwiches) - 1] + " is finished.")
print(finished_sandwiches)

# 7-9
sandwich_orders = ['tuna', 'salmon', 'pastrami', 'chicken', 'pastrami']
while 'pastrami' in sandwich_orders:
    sandwich_orders.remove('pastrami')
print("Pastrami is out of sale!")
print(sandwich_orders)

# 7-10
vacation_places = {}
while True:
    place = input("Where do you want to go for vacation? ")
    name = input("What's your name? ")
    vacation_places[name] = place
    choice = input("Fantastic!\nAny button to continue, q to quit: ")
    if choice == 'q':
        break

print("\nMina no vacation places:")
for name, place in vacation_places.items():
    print(name + " wants to go to " + place + ".")
