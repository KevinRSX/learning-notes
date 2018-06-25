# 6-5
Rivers = {
    'nile': 'egypt',
    'mississippi': 'u.s.',
    'Yangtze': 'china',
}

for key, value in Rivers.items():
    print("The " + key.title() + " runs through " + value.title())
for country in Rivers.keys():
    print(country.title())
for river in Rivers.values():
    print(river.title())

# 6-6
print("\n")
favorite_languages = {
    'jen': 'python',
    'sarah': 'C',
    'edward': 'ruby',
    'phil': 'python',
}
investigated = ['jen', 'young', 'smith', 'phil']
for person in favorite_languages.keys():
    if person in set(investigated):
        print("Thank you for attending our investigation, " + person.title())
    else:
        print("Please attend our investigation, " + person.title())