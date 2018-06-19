# list_name[start: end] returns the elements whose indexes are from start to end-1
# list_name[start:] from start to end of the list
# list_name[: end] from the beginning to end-1
# list_name[:] returns the whole list
players = ['charles', 'martina', 'micheal', 'florence', 'eli']
print(players[0: 3])
print(players[3:])
print(players[: 2])
print(players[:])

# list_name[-x:] returns the LAST x elements in the list (x>0)
print(players[-3:])

print("\n")

# traverse the list slice
print("Here are the first three players on my team:")
for player in players[:3]:
    print(player)

print("\n")

# copy the list
# using slice will make a whole copy of the VALUE
a_food = ['pizza', 'falafel', 'carrot cake']
b_food = a_food[:]  # copy the value
print("Using slice:")
a_food.append('cannoli')
b_food.append('ice cream')
print(a_food)
print(b_food)   # results are different

# not using slice will copy the list ITSELF
a_food.pop()    # back to the original list
b_food = a_food
print("Not using slice:")
a_food.append('cannoli')
print(a_food)
print(b_food)  # results are the same, a_food is changed
