# p121
# 8-3
def make_shirt(size, customization):
    print("Your size " + size + " T-shirt will be printed with " + customization)

make_shirt('M', 'Diu Lei Lou Mou')
make_shirt(customization = 'Interesting', size = 'L')

#8-4
def make_another_shirt(size = 'L', customization = 'I love python'):
    print("Your size " + size + " T-shirt will be printed with " + customization)

make_another_shirt()
make_another_shirt('M')
make_another_shirt(customization = 'I love C++')

# 8-5
def describe_city(city, country = 'iceland'):
    print(city.title() + " is in " + country.title())

describe_city('Reykjavik')
describe_city('Shanghai', 'China')
