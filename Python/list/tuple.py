# tuples use parentheses, not square brackets
# values in a tuple cannot be modified, just like constant arrays in C++
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])

# modification of elements will result in traceback
# dimensions[0] = 100 is not allowed
# However, it is allowed to modify the whole tuple
dimensions = (400, 100)

# traverse the tuple
for dimension in dimensions:
    print(dimension)
