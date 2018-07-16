# p125-126
# 8-6
def city_country(city, country):
    cc = '"' + city.title() + ", " + country.title() + '"'
    return cc

print(city_country("santago", "chile"))

# 8-7
def make_album(author, album, num = ''):
    album_info = {"author" : author, 'album' : album}
    if num:
        album_info['number'] = num
    return album_info

print(make_album("Jay-Z", "Reasonable doubt"))
print(make_album("Owl City", "Cinema", 8))

# 8-8
while True:
    print("Please enter the album information (q to quit): ")
    author = input("Author name: ")
    if author == 'q':
        break
    album = input("Album name: ")
    if album == 'q':
        break
    num = input("How many songs does the album has (leave blank if you don't remember)? ")
    if num == 'q':
        break
    print(make_album(author, album, num))
