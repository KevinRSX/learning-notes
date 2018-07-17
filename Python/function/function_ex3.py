# p129
# 8-9
magicians = ['lei', 'lou', 'mou']
def show_magicians(magists):
    for magist in magists:
        print(magist.title())


show_magicians(magicians)

# 8-10
def make_great(magists):
    for i in range(len(magists)):
        magists[i] += ", the great"

make_great(magicians)
show_magicians(magicians)
