# 第七章 用户输入和while循环
## 7.1 函数input()的工作原理

函数`input()`让程序暂停运行，等待用户输入一些文本。获取用户输入后，python将其存储在一个变量中。
```python
message = input("Tell me something and I'll repeat: ")
print(message)
```
`input()`函数的参数是显示的内容，它会将用户输入的文本作为字符串返回。

</br>

要注意，`input()`函数的返回值类型是字符串，想要将其转化为数值，应当使用`int()`函数
```python
age = input("How old are you?\n")
age = int(age)
```
这样，用户输入的数字才会被正确地转化为整数。

## 7.2 while循环简介

for循环的目的是针对集合中每一个元素进行操作，而while是为了不断运行，直到指定条件不满足为止。

### 7.2.1 使用
以下代码可以从1数到5：
```python
current_num = 1
while current_num <= 5:
    print(current_num)
    current_num += 1
```

### 7.2.2 使用标志
由于一个程序中可能导致循环退出的条件有很多，那么我们需要使用**标志**来让循环退出。在循环开始前把它设置为True，当满足退出循环的条件时，将其改为False。
```
active = True
while active:
    if needs_to_break:
        active = False
```

### 7.2.3 使用break退出循环
若要立即退出循环，使用break语句即可。它用于控制程序的流程，可以用于控制哪些代码将被执行，哪些代码不被执行。

### 7.2.4 在循环中使用continue
continue的用途是略过本次循环中所有剩余代码，直接执行下一次循环。
```python
current_number = 0
while current_number < 10:
    current_number += 1
    if current_number % 2 == 0:
        continue
    print(current_number)
```
比如这段代码就print出了10以内所有奇数

### 7.2.5 避免无限循环
在循环代码中，一定要注意更新循环条件
```python
x = 1
while x <= 5:
  print(x)
```
像这样的代码，就会陷入无限循环。如果出现这种情况，可以用`Ctrl+C`退出控制台

## 7.3 使用while循环来处理列表和字典
通常，当我们想要对列表或字典的内容做出修改时，我们可以使用while循环。


### 7.3.1 删除包含特定值的所有列表元素
第三章中的`remove()`函数，可以删除列表中带特定值的元素，但是它只能删除1次，使用while语句可以实现对某个元素的完全删除：
```python
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat']
while 'cat' in pets:
    pets.remove('cat')
print(pets)
```
在这段代码中，while语句的条件是指判断cat是否还在列表里，而remove会每次删除一个cat，所以不断删除，直到列表里再也没有cat元素，任务也就完成了。

### 7.3.2 使用用户输入来填充字典
Recall: 想要在词典中添加内容，方法是
```python
dict_name[key_name] = value_name
```
那么想要取得用户输入并将其添加进字典，就可以
```python
dict_name = {}
while True:
  key = input("prompt1")
  value = input("prompt2")
  dict_name[key] = value
```

## Demos:
1. [input.py](input.py)
2. [input_exercise.py](input_exercise.py)
3. [while_basic.py](while_basic.py)
4. [while_ex1.py](while_ex1.py)
5. [while_transverse.py](while_transverse.py)
6. [while_ex2.py](while_ex2.py)
