message = input("Tell me something and I'll repeat: ")
print(message)

height = input("How tall are you in cm? ")
height = int(height)
if height < 140:
    print("You are not tall enough to ride!")
else:
    print("Enjoy your journey!")