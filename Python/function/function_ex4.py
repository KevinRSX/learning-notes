# p132
# 8-12
def wich_plus(*foods):
    print("Your sandwich contains: ")
    for food in foods:
        print(food.title())

# wich_plus('yogurt')
# wich_plus('cheeese', 'tuna', 'cucumber')

# 8-14
def build_car(made, type, **car_info):
    car = {'made': made, 'type': type}
    for key, value in car_info.items():
        car[key] = value
    print(car)

build_car('subaru', 'outback', color = 'blue', tow_package = True)
