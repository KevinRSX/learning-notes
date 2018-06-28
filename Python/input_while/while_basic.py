current_num = 1
while current_num <= 5:
    print(current_num)
    current_num += 1

name = input("Enter your name: ")
prompt = "Say something and I will repeat,"
prompt += "\nand please press q to quit: "
message = input(prompt)
while message != 'q':
    print("OK! " + name + ", " + message)
    message = input(prompt)
print("Bye!")


prompt = "Please enter the name of a city you have visited"
prompt += "\n(Enter 'q' when you are done): "

while True:
    city = input(prompt)
    if city == 'q':
        break
    else:
        print("Hmmm, " + city + ".., I also love this city!")

current_number = 0
while current_number < 10:
    current_number += 1
    if current_number % 2 == 0:
        continue
    print(current_number)
