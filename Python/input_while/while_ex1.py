# p110
# 7-4

sauce = input("Enter a sauce ('q' to quit): ")
while sauce != 'q':
    print(sauce + " will be added soon!")
    sauce = input("Enter a sauce ('q' to quit): ")

# 7-5
age = input("Please enter your age (q to quit): ")
while age != 'q':
    age = int(age)
    if age < 3:
        print("You are free to go!")
    elif age <= 12:
        print("Charging $10")
    else:
        print("Charging $15")
    age = input("Please enter your age (q to quit): ")
