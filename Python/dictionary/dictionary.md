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
</br></br></br>

### 6.2.3 空字典
当我们使用字典来存储用户提供的数据或自动生成大量键值对代码时，通常会先定义一个空字典，大括号为空即可：
```python
alien_0 = {}
```

##Demos:
1. [dictionary.basic.py](dictionary_basic.py)