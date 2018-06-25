# 第六章 字典
## 6.1 一个简单的字典

字典可以存储特定的信息，将其归类。

## 6.2 使用字典
在python中，字典是一系列键-值对(key-value)，可以使用键访问与之相关联的值。值可以是数字、字符串、列表、字典以及任何python对象。
```python
alien_0 = {'color': 'green'}
```
最简单的字典只有一个键-值对，color是键，green是与color相关联的值。

字典可以直接print：
```python
print(alien_0)
```
```
{'color': 'green', 'points': 5}
```
### 6.2.1 访问字典中的值
要获取和某个键相关的值，可依次指定字典名和放在方括号内的键:
```
>>> alien_0['color']
>>> green

```
将获取的值储存起来使用：
```python
new_points = alien_0['points']
print("You just earned " + str(new_points) + " points!")
```
```
You just earned 5 points!
```

### 6.2.2 添加键-值对
字典是一种动态结构，要添加键-值对直接声明即可：
```python
alien_0['x_position'] = 0
alien_0['y_position'] = 25
```
注意：在字典中，键值对的排列顺序与添加顺序没有关系，python仅关心键值对的对应关系。

### 6.2.3 空字典
当我们使用字典来存储用户提供的数据或自动生成大量键值对代码时，通常会先定义一个空字典，大括号为空即可：
```python
alien_0 = {}
```

### 6.2.4 修改字典中的值
想要修改字典中的值，像列表一样操作（直接赋值修改）即可。考虑如下代码：
```python
alien_0 = {'x-position': 0, 'y-position': 25, 'speed': 'medium'}
print("Original x-position: " + str(alien_0['x-position']))
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    x_increment = 3

alien_0['x-position'] += x_increment
print("New x-position: " + str(alien_0['x-position']))
```
x_increment的值将随对象的speed值而改变，如果要调整外星人的速度，只需要修改speed值：
```python
alien_0['speed'] = 'high'
```
这样每次x的增量就变成了3.

### 6.2.5 删除键-对
用del语句可以永久删除一个键对：
```python
del dict_name[dict_key]
```

### 6.2.6 分行字典
当字典内元素数较多时，往往将其分行，要注意缩进，且大括号不可换行：
```python
favorite_languages = {
    'jen': 'python',
    'sarah': 'C',
    'edward': 'ruby',
    'phil': 'python',
}
```

## 6.3 遍历字典
### 6.3.1 遍历所有键-值对
要取得一个键-值对的内容，要使用`items()`方法
```python
for key, value in user_0.items():
    print("\nKey: " + key)
    print("Value: " + value)
```
该方法返回了两个值，储存到`key`和`value`里，使得循环变量可以直接得到一个键值对的值

</br>

### 6.3.2 遍历所有键
与上一节同理，使用`keys()`方法即可，并且只需要储存一个循环变量：
```python
for name in favorite_languages.keys():
    print(name.title())
```
在python中，遍历字典的默认方式是遍历键，因此`for name in favorite_languages.keys()`和`for name in favorite_languages`是等价的，
但加上方法会使程序更易理解。

</br>

### 6.3.4 遍历字典中所有值
同样，使用`values()`:
```python
print("The following languages have been mentioned:")
for language in favorite_languages.values():
    print(language.title())
```
`set()`函数可以帮助我们找出列表中独一无二的元素，省略掉相同者。
```python
for language in set(favorite_languages.values()):
    print(language.title())
```
这样的话，多余的python就会在输出中被省略掉，有助于我们剔除重复项。

</br>

## 6.4 嵌套
嵌套存储往往分为：
1. 列表中嵌套字典
2. 字典中嵌套列表
3. 字典中嵌套字典

</br>

### 6.4.1 字典列表
一个字典alien_0可以包含一个外星人的信息，如果想要同时管理一群外星人，那就要需要字典列表，即将字典作为列表中的元素
```python
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}
aliens = [alien_0, alien_1, alien_2]
```

</br>

### 6.4.2 在字典中存储列表
如果我们想储存一个pizza字典，它有crust和toppings两个属性，其中配料不止一种，此时就应当用toppings作为列表存储多个配料
```python
pizza = {
    'crust': 'thick',
    'toppings': ['mushrooms', 'extra cheese']
}
```
</br>

### 6.4.3 在字典中存储字典
这种情况的代码相当复杂， 比如在一个网站中，想要存储几位用户的信息，对于每位用户，都要储存其居住地，姓，名
```python
users = {
    'aeinstein':{
        'first': 'albert',
        'last': 'einstein',
        'location': 'princeton',
    },
    'mcurie':{
        'first': 'marie',
        'last': 'curie',
        'location': 'paris',
    }
}
```
为了处理大量数据方便，每位用户的字典最好应包含相同的键
</br></br></br>
## Demos:
1. [dictionary_basic.py](dictionary_basic.py)
2. [dictionary_manipulation.py](dictionary_manipulation.py)