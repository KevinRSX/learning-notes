# 第八章 函数

## 8.1 定义函数

这是一段最简单的函数程序
```python
def greet():
    """show greeting on screen"""
    print("Hello!")

greet()
```
python中函数定义以def表示，第二行中的`"""`被称为文档字符串（docstring），用于描述函数的用途，python使用它们生成文档。此外，注意冒号和缩进。

python传递参数不需要在函数头里写明参数类型。

```python
def greet(name):
    """show greeting on screen"""
    print("Hello! " + name)
greet('Jenny')
```
</br>

## 8.2 传递实参

调用函数时，python必须将函数调用中的每个实参都关联到函数定义中的形参，基于实参顺序的关联方式被称为位置实参，基于传递实参时所写的变量名的关联方式被称为关键字实参。

### 8.2.1 位置实参
顾名思义，由实参位置决定形参的内容。具体内容略。

### 8.2.2 关键字实参
调用时，直接在实参中将名称和值关联，使得在向函数传递实参时，不会混淆。

```python
def describe_pet(animal_type, pet_name):
    """display information about the pet"""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet(animal_type = 'hamster', pet_name = 'harry')
```
比如这个函数在调用的的时候直接写出要使用不同的形参名，于是解释器可以直接对应到相应的形参上。这样顺序就无关紧要了。

### 8.2.3 默认值
默认值和C++里的默认参数类似，在调用函数中，如果用户提供了实参，python就会使用提供的实参，反之就会使用函数头的默认参数。

```python
def describe_pet(pet_name, animal_type = 'dog'):
    """display information about the pet"""
    print("\nI have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('willie')
```

注意，和C++一样，默认参数必须位于非默认参数的右边，解释器将会通过位置将实参与形参对应。当要设置多个默认参数时，想要在不使用右边默认特性的前提下使用左边的默认参数特性，必须使用关键字实参。

```python
def describe_pet(pet_name, animal_type = 'dog', loveit = 'yes'):
```
考虑这段函数的调用，它有两个默认参数，当我们想要省略提供给`animal_type`的参数时，就不可以再使用位置实参提供`loveit`的值，因为一旦把`loveit`的值放在第二个参数的位置，解释器会认为我们想要设置`animal_type`的值。要正确调用，必须用关键字实参：
```python
describe_pet(pet_name = 'harry', loveit = 'of course')
```
<br/>

## 8.3 返回值

### 8.3.1 返回简单值
拥有返回值的函数可以处理一些数据，并返回一个或一组值。
```python
def get_formatted_name(first, last):
    """return formatted name"""
    full_name = first + ' ' + last
    return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)
```
以上就是一个返回简单值的例子，它将姓和名拼接在一起返回了它们的`title()`值，这对处理大量数据十分有用。

### 8.3.2 让实参成为可选的
使实参成为可选的，可以使使用函数的人在必要时提供必要的信息，以处理特殊状况。这个目的可以通过默认参数达到。

```python
def get_decent_name(first, last, middle = ''):
    """return formatted name, with middle names somehow"""
    if middle:
        full_name = first + ' ' + middle + ' ' + last
    else:
        full_name = first + ' ' + last
    return full_name.title()
```
这段代码可以区分出有无中间名的情况，用户需要做的是在有中间名的情况下把它放到最后。把中间名设置为空字符，可以用if语句来判断用户是否给它设置了实参。

### 8.3.3 返回字典
python中的函数可以返回任何类型的值，包括字典，列表等复杂的数据结构。
```python
def build_person(first_name, last_name):
    """return a dictionary that contains personal inforamtion"""
    person = {'first': first_name, 'last': last_name}
    return person
```
这个函数接受姓名的组成部分，并返回一个表示人的字典。这样做可以将一个人的信息快速归类，并且在调用函数里可以方便地取用。更重要的是，当我们想要加入更多信息，需要修改的内容也不多:

```python
def build_person(first_name, last_name, age = ''):
    """return a dictionary that contains personal inforamtion"""
    person = {'first': first_name, 'last': last_name}
    if age:
        person['age'] = age
    return person
```
对`build_person()`函数增加代表年龄的默认参数，可以随时添加年龄信息到一个人里。

### 8.3.4 结合使用函数和while循环
在while循环中调用函数，用其处理用户输入的顺序，会使代码更加整洁。要注意设置退出循环的条件。
<br/>

## 8.4 传递列表
将列表传递给函数，处理数据的效率会提升很多。函数处理列表的方式和处理简单数据一样，亦是将列表储存在形参中，通过处理形参的方式来处理列表。

```python
def greet(names):
    """greet every person in the list"""
    for name in names:
        msg = "Hello, " + name.title() + "!"
        print(msg)
```
这是一个很简单的例子。把列表存储在实参里，用通常的方法处理。

### 8.4.1 在函数中修改列表
在传递列表时，参数保存的是列表本体，因此在函数中对列表所做的修改是永久性的。
```python
unprinted_designs = ['design_a', 'design_b', 'design_c']
completed_models = []
print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)
```
思考这段代码，`print_models()`函数接受两个列表作为参数，将未打印的模型pop出来，一一转移到打印完的模型里，`show_completed_models()`函数用于展示以完成的模型。这是一个修改列表的例子。

### 8.4.2 禁止函数修改列表
如果不希望函数修改列表，可以用切片表示法`[:]`来创建列表的副本，在调用时可以这样写。
```python
function_name(list_name[:])
```
在这种情况下，函数接收到的是副本，在函数内所做的一切修改将不会影响到外部。但传递信息量大的列表时，会使得效率较低。


## 8.5 传递任意数量的实参
当定义函数时不知道函数将要处理几个实参的时候，python会允许函数从调用语句中收集任意数量的实参
```python
def make_pizza(*toppings):
    print(toppings)
```
上述`*toppings`形参的作用是创建一个名为toppings的空元组，将收到的所有值都封装到这个元组中。我们可以用以下方式来调用它：
```python
make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
```
这个元组可以储存一个参数，也可以储存多个参数。

### 8.5.1 结合使用位置实参和任意数量实参
若要将任意数量参数和普通参数结合使用，那么必须在函数定义中将接纳任意数量实参的形参放在最后。Python将先匹配位置实参和关键字实参，再将余下的实参都收集到最后一个形参中。

### 8.5.2 使用任意数量的关键字形参
当我们需要接收任意数量的实参，但预先不知道传递给函数的是什么信息时，可以将函数编写成能够接收任意数量的键-值对 -- 调用语句提供了多少就接收多少的形式。函数头可以这样写：
```python
def build_profile(first, last, **user_info):
```
`**user_info`的两个星号表示形参是一个空的字典，调用时，在最后可以添加任何不同的信息。
```python
user_profile = build_profile('albert', 'einstein', location = 'princeton', field = 'physics')
```

## 8.6 模块
函数的一大优点是，可以通过使用它们将代码块和主程序分离。将函数储存在被称为`module`的独立文件之中，再让模块导入主程序中，可以达到代码重用的目的。

好处：
1. 隐藏程序代码细节，侧重于高层逻辑
2. 在不同程序中重用函数
3. 我们可以使用其他程序员编写的程序

<br/>
### 8.6.1 导入整个模块
要导入整个模块，我们应当先创建一个包含函数定义的模块的文件。模块的拓展名是`.py`。再创建一个使用模块的文件。假如模块名为`pizza.py`，那么就应当在使用该函数的文件`making_pizza.py`的第一行加上代码
```python
import pizza
```
`import`的语句和C中`include`用法相似，python解释器会直接在目录中找到相应文件，然后把代码统统复制粘贴到使用程序中。

要调用模块中的函数，应当用下面的语法
```python
module_name.function_name()
```

<br/>
### 8.6.2 导入特定函数
想要导入特定函数时，语法如下：
```python
from module_name import function_name
```

此时调用函数无需句点，因为函数已经被显式导入，指定名称即可。

<br/>
### 8.6.3 指定别名
若担心名称冲突，可以用`as`语句指定别名。要给函数指定别名，语法如下：
```python
from module_name import function_name as fn
```

给模块指定别名语法如下：
```python
import module_name as mn
```

<br/>
### 8.6.4 导入模块所有函数
```python
from module_name import *
```
这个做法可以使我们导入模块中所有函数，且不必使用句点表示法。但这不是一个好的做法，相当容易导致变量名冲突。

<br/>
### 8.7 函数编写指南
1. 紧跟函数定义后写函数文档注释。
2. 默认参数和关键字实参等号两边不加空格
