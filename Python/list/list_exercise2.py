for number in range(1, 21):
    print(number)

large_num = list(range(1, 1000001))
print("Max: " + str(max(large_num)))
print("Min: " + str(min(large_num)))
print("Sum: " + str(sum(large_num)))

odd_numbers = list(range(1, 20, 2))
print(odd_numbers)

three_multipliers = list(range(3, 31, 3))
print(three_multipliers)

cubes = [val**3 for val in range(1, 11)]
print(cubes)