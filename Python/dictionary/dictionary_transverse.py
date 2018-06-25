# 6.3.1
user_0 = {
    'username': 'efermi',
    'first': 'enrico',
    'last': 'fermi',
}

for key, value in user_0.items():
    print("\nKey: " + key)
    print("Value: " + value)

print("\n")

favorite_languages = {
    'jen': 'python',
    'sarah': 'C',
    'edward': 'ruby',
    'phil': 'python',
}

for key, value in favorite_languages.items():
    print(key.title() + "'s favorite language is " + value.title())

# 6.3.2
print("\n")
for name in favorite_languages.keys():
    print(name.title())

print("The following languages have been mentioned:")
for language in favorite_languages.values():
    print(language.title())

print("\n")
for language in set(favorite_languages.values()):
    print(language.title())