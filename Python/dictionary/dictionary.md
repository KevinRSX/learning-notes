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
</br></br></br>
## Demos:
1. [dictionary_basic.py](dictionary_basic.py)
2. [dictionary_manipulation.py](dictionary_manipulation.py)