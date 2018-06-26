# p104
# 7-1
car_type = input("What type of car do you want?\n")
if (car_type[0] == 'a' or car_type[0] == 'e' or car_type[0] == 'i' or car_type[0] == 'o' or car_type[0] == 'u' or
        car_type[0] == 'A' or car_type[0] == 'E' or car_type[0] == 'I' or car_type[0] == 'O' or car_type[0] == 'U'):
    print("Let me see if I can get you an " + car_type)
else:
    print("Let me see if I can get you a " + car_type)

# 7-3
num = int(input("Give me an number: "))
if num % 10:
    print(str(num) + " is not the integer multiple of 10")
else:
    print(str(num) + " is the integer multiple of 10")