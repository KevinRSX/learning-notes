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
