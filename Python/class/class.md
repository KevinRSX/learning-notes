# 第九章 类

## 9.1 创建和使用类

### 9.1.1 创建Dog类
python中，首字母大写的名称即是类。类的构造函数是`__init__()`
```python
def __init__(self, name, age):
      """initialize a dog's properties"""
      self.name = name
      self.age = age
```
形参中，`self`是必不可少的，它是指向实例本身的引用，使实例能够访问类中的属性和方法。在声明类时不需要提供实参。在函数中，将变量名加上self前缀，意味着类中所有方法都可以使用这些变量，可以通过类的实例来访问变量，**相当于这些变量是public的。**

在其他类方法的参数列表中，亦要使用`self`参数。
```python
def sit(self):
def roll_over(self):
```

<br/>

### 9.1.2 根据类创建实例
创建实例的一般语法：
```python
instance_name = class_name(paralist)
# parameter list align with constructor
```

访问属性：
```python
print("My dog's name is " + my_dog.name.title() + ".")
```

调用方法：
```python
my_dog.sit()
```

<br/>

## 9.2 使用类和实例
使用实例时，一个重要任务是修改其属性。可以直接修改，也可以用特定方式。

### 9.2.1 Car类
