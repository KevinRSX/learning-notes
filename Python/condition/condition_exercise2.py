name_list = ['john', 'mary', 'helen', 'admin', 'david']
for name in name_list:
    if name == 'admin':
        print("Hello admin, would you like to see a status report?")
    else:
        print("Hello " + name + ", thank you for logging in again.")

name_list = []
if name_list:
    for name in name_list:
        if name == 'admin':
            print("Hello admin, would you like to see a status report?")
        else:
            print("Hello " + name + ", thank you for logging in again.")
else:
    print("We need to find some users!")

print("\n")
#####################################

current_users = ['ori', 'newton', 'jason', 'dennis', 'marcus']
new_users = ['basaka', 'mary', 'jason', 'bush']
for new_user in new_users:
    if new_user in current_users:
        print("User name occupied, please use a new name")
    else:
        print(new_user + ", Congratulations. Signing up success!")

print("\n")
#####################################

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
for number in numbers:
    if number == 1:
        print("1th")
    elif number == 2:
        print("2nd")
    elif number == 3:
        print("3rd")
    else:
        print(str(number) + "th")
