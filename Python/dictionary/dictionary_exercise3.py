# p99

# 6-8
sumo = {'type': 'dog', 'owner': 'john'}
Aimer = {'type': 'cat', 'owner': 'chak'}
prpr = {'type': 'rabbit', 'owner': 'chris'}

pets = [sumo, Aimer, prpr]
for pet in pets:
    print(pet)

# 6-9
favorite_places = {
    'Tohsaka': ['London', 'Paris'],
    'Harris': ['Hong Kong', 'Bangkok'],
    'Ming': ['Seoul', 'l.a.']
}
for key, value in favorite_places.items():
    print(key + "'s favorite places are ")
    for city in value:
        print('\t' + city.title())

# 6-10
print("\n")
cities = {
    'shanghai': {
        'country': 'china',
        'population': 23,
        'fact': 'used to be elegant but now many hard disks inside'
    },
    'Tokyo': {
        'country': 'japan',
        'population': 14,
        'fact': 'clean and tidy but also dark'
    },
}

for key, value in cities.items():
    print("City: " + key)
    print("\tCountry: " + value['country'].title())
    print("\tPopulation: " + str(value['population']))
    print("\tFact: " + value['fact'].title())
