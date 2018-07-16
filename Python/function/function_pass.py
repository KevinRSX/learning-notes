def greet(names):
    """greet every person in the list"""
    for name in names:
        msg = "Hello, " + name.title() + "!"
        print(msg)

usernames = ['hannah', 'ty', 'margot']
# greet(usernames)

def print_models(unprinted_designs, completed_designs):
    """simulate to print all designs until there are no unprinted works left
    move each design to the new list after they are printed"""
    while unprinted_designs:
        current_design = unprinted_designs.pop()
        print("Printing model: " + current_design)
        completed_designs.append(current_design)

def show_completed_models(completed_models):
    """show all the printed models"""
    print("\nThe following models have been printed:")
    for completed_model in completed_models:
        print(completed_model)

unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []
print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)
