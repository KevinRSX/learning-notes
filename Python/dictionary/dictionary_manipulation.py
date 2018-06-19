alien_0 = {'color': 'green'}
print("The alien is " + alien_0['color'] + '.')

alien_0['color'] = 'yellow'
print("The alien is " + alien_0['color'] + '.\n')

alien_0 = {'x-position': 0, 'y-position': 25, 'speed': 'medium'}
print("Original x-position: " + str(alien_0['x-position']))
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    x_increment = 3

alien_0['x-position'] += x_increment
print("New x-position: " + str(alien_0['x-position']))

# delete key-value
alien_0 = {'color': 'green', 'points': 5}
print(alien_0)
del alien_0['points']
print(alien_0)

print("\n")

# multi-line dictionary
favorite_languages = {
    'jen': 'python',
    'sarah': 'C',
    'edward': 'ruby',
    'phil': 'python',
}
print("Edward's favorite language is " + favorite_languages['edward'].title())