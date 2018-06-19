# function range(a,b), create a list of numbers in the interval [1,5)
# e.g. range(1,5) gives 1,2,3,4
for value in range(1, 5):
    print(value)

# convert a series of numbers to a list, use list()
numbers = list(range(1, 6))
print(numbers)

# the third argument of range() is the step size
even_numbers = list(range(2, 11, 2))
print(even_numbers)
print("\n")

# power calculation in python is denoted by **
squares = []
for value in range(1, 11):
    squares.append(value**2)
print(squares)

# max(num_list), min(num_list), and sum(num_list)
digits = list(range(0, 10))
print(max(digits))      # 9
print(min(digits))      # 0
print(sum(digits))      # 45

print("\n")

# list parsing
squares = [value**2 for value in range(1, 11)]
print(squares)