# 6.4.1
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}
aliens = [alien_0, alien_1, alien_2]
for alien in aliens:
    print(alien)

aliens = []
for alien_number in range(30):  # generate 30 aliens
    new_alien = {'color': 'green', 'points': 5, 'speed': 'low'}
    aliens.append(new_alien)
for alien in aliens[:3]:
    if alien['color'] == 'green':
        alien['color'] = 'yellow'
        alien['speed'] = 'medium'
        alien['points'] = 10
for alien in aliens[:5]:
    print(alien)
print("...")
print("Total number of aliens: " + str(len(aliens)))

# 6.4.2
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese']
}

print("You ordered a " + pizza['crust'] + '-crust pizza with the following toppings:')
for topping in pizza['toppings']:
    print("\t" + topping)

# 6.4.3
users = {
    'aeinstein':{
        'first': 'albert',
        'last': 'einstein',
        'location': 'princeton',
    },
    'mcurie':{
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
    }
}

for username, user_info in users.items():
    print("Username: " + username)
    full_name = user_info['first'] + " " + user_info['last']
    location = user_info['location']
    print("Full name: " + full_name.title())
    print("Location: " + location.title())