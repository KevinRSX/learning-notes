def get_formatted_name(first, last):
    """return formatted name"""
    full_name = first + ' ' + last
    return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
# print(musician)

def get_decent_name(first, last, middle = ''):
    """return formatted name, with middle names somehow"""
    if middle:
        full_name = first + ' ' + middle + ' ' + last
    else:
        full_name = first + ' ' + last
    return full_name.title()

musician = get_decent_name('jimi', 'hendrix')
# print(musician)
musician = get_decent_name('john', 'hooker', 'lee')
# print(musician)

def build_person(first_name, last_name, age = ''):
    """return a dictionary that contains personal inforamtion"""
    person = {'first': first_name, 'last': last_name}
    if age:
        person['age'] = age
    return person

musician = build_person('jimi', 'hendrix', 38)
# print(musician)

while True:
    print("\nPlease tell me your name:")
    print("(enter 'q' at any time to quit)")

    f_name = input("First name: ")
    if f_name == 'q':
        break

    l_name = input("Last name: ")
    if l_name == 'q':
        break

    formatted_name = get_formatted_name(f_name, l_name)
    print(formatted_name)
