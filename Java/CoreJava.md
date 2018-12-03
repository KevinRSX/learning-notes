# Chapter 5 Inheritence

## 5.1 Classes, Superclasses, and Subclasses

### 5.1.10 Protected Access

`protected` key word: Used to restrict a method to subclasses only to allow subclass methods to access a superclass field. Declare a class feature as protected.

- protected field is not recommended.
- protected method is sometimes used. Example `Ojbect.clone()`



Four Java access modifiers:

1. `private`: visible to the class only
2. `public`: visible to the world
3. `protected`: visible to the package and all subclasses
4. Default: visible to the package



## 5.2 `Object`: The Cosmic Superclass

The `Object` class is the ultimate ancestor - every class in Java extends `Object`.

A variable of type `Object` is only useful as a generic holder for arbitrary values. To do specific things, need to downcast.

```java 
Object obj = new Employee("Harry Hacker", 35000);
Employee e = (Employee) obj;
```

In Java, only the values of primitive types are not objects. All array types, no matter whether they are arrays of objects or arrays of primitive types, are class types that extend the `Object` class.

```java
Employee[] staff = new Employee[10];
obj = staff;
obj = new int[10];
```



### 5.2.1 The `equals` method

The `equals` method, as implemented in the `Object` class, determines whether two object variables refer to  the same object.

Sometimes, we want to implement state-based equality testing, e.g., the value of two String objects.

The following example is a method in Employee class that overrides the original one.

```java
public class Employee
{
    public boolean equals(Object otherObject)
    {
        // a quick test to see if the objects are identical
        if (this == otherObject) return true;
        
        // must return false if the explicit parameter is null
        if (otherObject == null) return false;
        
        // if classes don't match, they cannot be equal
        if (getClass() != otherObject.getClass())
            return false;
        // now we know otherOjbect is a non-null Employee
        Employee other = (Employee) otherObject;
        
        // test whether the fields have identical values
        return Objects.equals(name, other.name) && salary == other.salary \
            && Objects.equals(hireDay, other.hireDay);
    }
}
```



### 5.2.2 Equality Testing and Inheritence

There is possibility that in equality testing, the `otherObject` is a subclass. We often use the following instead of simply test if the return values of `getClass()` method are the same:

```java
if (!(otherObject instanceof Employee)) return false;
```



According to Java language specification, it is required that `equals` method has some properties. (Refer to p231). The`instanceof` test could disobey this rule.

Two distinct scenarios:

- If subclasses can have their own notion of inequality, then the symmetry requirement forces you to use the `getClass` test.
- If the notion of equality is fixed in the superclass, then you can use the `instanceof` test and allow objects of different subclasses to be equal to one another.

Example: If the `manager` class has its own method to test equality, say, comparing bonuses, then we must use `getClass` test. On the other hand, if all subclasses of `Employee` class tests equality by comparing id of each employee, then we can use `instanceof` test. In this case, we should declare `Employee.equals()` as final.



Consider this declaration in the scope of class `Employee`

```java
public boolean equals(Employee other);
```

This defines an UNRELATED METHOD instead of overriding the `equals` method in `Object` class as the signatures are different.

To prevent yourself from this error, use `@Override` to tag methods that are intended to override superclass methods.

```java
@Override public boolean equals(Object other);
```

In this sense, if we change the parameter type to `Employee`, the compiler will report an error.



### 5.2.3 The `hashCode` Method

A hash code is an integer that is derived from an object.

The `String` class uses the following algorithm to compute the hash code:

```java
int hash = 0;
for (int i = 0; i < length(); i++)
    hash = 31 * hash + charAt(i);
```

The `hashCode ` method is defined in the `Object` class. Therefore, every object has a default hash code derived from the object's memory address.

If you redefine the `equals` method, you will also need to redefine the `hashCode` method for objects that users might insert into a hash table. For example,

```java
public class Employee
{
    public int hashCode()
    {
        return 7*Objects.hashCode(name) + 11*Double.hashCode(salary) \
            + Objects.hashCode(hireDay);
    }
}
```

To simplify, call `Objects.hash` with all of them:

```java
return Objects.hash(name, salary, hireDay);
```



Definitions of `equals` and `hashCode` must be compatible. If `x.equals(y)` is true, then `x.hashCode()` must returns the same value as `y.hashCode()`



### 5.2.4 The `toString` Method

Returns a string representing the value of its object.

Most `toString` methods follow this format: the name of the class, then the field values enclosed in squared brackets.

```java
java.awt.Point[x=10,y=20]
```

Whenever an object is concatenated with a string by the "+" operator, the Java compiler automatically invokes the `toString` method to obtain a string representation of the object.



## 5.3 Generic Array Lists

`ArrayList` is a generic class with a type parameter. To specify the type of the element objects that the array list holds, append a class name enclosed in angle brackets, such as `ArrayList<Employee>`.

Declaration:

```java
ArrayList<Employee> staff = new ArrayList<Employee>();
```

Type parameter can be omitted on the right-hand side:

```java
ArrayList<Employee> staff = new ArrayList<>();
```



The array list manages an internal array of object references. If you call `add` and the internal array is full, the array list automatically creates a bigger array and copies all the objects from the smaller to the bigger array. To prevent costly reallocation, use `ensureCapacity()` method or pass an initial capacity.

```java
ArrayList<Employee> staff = new ArrayList<>(100);
```



### 5.3.1 Accessing Array List Elements

To get the `i`th element,

```java
staff.get(i);
```

To set the `i`th element,

```java
staff.set(i, harry);
```

Note: we should not call `list.set(i,x)` until the size of the array list is larger than `i`. Use the `add` method instead of `set` to fill up an array, and use `set` only to replace a previously added element.



## 5.4 Object Wrappers and Autoboxing

All primitive types have class counterparts. These kinds of classes are usually called `wrappers`. `Integer`, `Long`, `Float`,`Double`, `Short`, `Byte`, `Character`, `Boolean`.

The wrapper classes are immutable and `final`.

The type parameter inside the angle brackets cannot be primitive types. Therefore, we have to declare an array list of `Integer` objects to get create an array list such that each element is an integer.

```java
ArrayList<Integer> list = new ArrayList<>(); 
```



Autoboxing: The call

```java
list.add(3);
```

will be automatically translated to

```java
list.add(Integer.valueOf(3));
```

Conversely, when you assign an `Integer` object to an `int` value, it is automatically unboxed. Automatically boxing and unboxing even works with arithmetic expressions.

However, we must use `equals` method to compare wrapper objects. Also there are some subtleties:

- Wrapper class references can be `null`, so possible that autounboxing will throw a `NullPointerException`:

- ```java
  Integer n = null;
  System.out.println(2 * n); // exception occurs
  ```

- If you mix Integer and Double types in a conditional expression, then the Integer value is unboxed, promoted to double, and boxed into a double.

  ```java
  Integer n = 1;
  Double x = 2.0;
  System.out.println(true ? n : x);	//prints 1.0
  ```



Designers of Java found the wrappers a convenient place to put certain basic methods, such as those for converting strings of digits to numbers.

```java
int x = Integer.parseInt(s);
```



It should be noticed that wrappers are immutable classes, so a function like this won't work.

```java
public static void triple(Integer x)
	{
		x = x * 3;
	}
```



## 5.5 Methods with a Variable Number of Parameters

It's possible to provide methods that can be called with a variable number of parameters. (Sometimes called "varargs" methods)

Consider the function `printf()`

```java
public class PrintStream
{
    public printStream printf(String fmt, Object... args){ return format(fmt, args); }
}
```

You can define your own methods of this kind, and you can specify any type for parameters, even a primitive type.

We can redefine an existing function whose last parameter is an array to a method with variable parameters, without breaking the existing code.



## 5.6 Enumeration Class



## 5.7 Reflection



## 5.8 Design Hints for Inheritance

1. Place common operations and fields in the superclass.
2. Don't use protected fields.
3. Use inheritance to model the "is-a" relationship
4. Don't use inheritance unless all inherited fields make sense.
5. Don't change the expected behavior when you override a method.
6. Use polymorphism, not type information.
7. Don't overuse reflection.



# Chapter 6 Interfaces, Lambda Expressions, and Inner Classes

## 6.1 Interfaces

### 6.1.1 The Interface Concept

An interface is not a class but a set of requirements for classes that want to conform to the interface.

For example, the `sort` method of the `Array` class can sort an array of objects provided that the objects must belong to classes that implement the `Comparable` interface which has a `compareTo` method.

An interface does not have instance fields or implementations of methods. They are the job of classes that implement them.



To make a class implement an interface, you carry out two steps:

1. Declare that your class intends to implement the given interface
2. Supply definitions for all methods in the interface



We will find it useful to supply a type parameter for the generic `Comparable` interface.

```java
class Employee implements Comparable<Employee>
{
	public int compareTo(Employee other)
    {
    	return Double.compare(salary, other.salary);
    }
}
```



The reason of neccesity to implement `Comparable`  interface: When making a method call, the compiler needs to be able to check that the method actually exists. In standarad library, the implementation of `sort`  is to use explicit upcasting to make two objects `Comparable` objects.

```java
if (((Comparable) a[i]).compareTo(a[j] > 0){
    // rearrange a[i] and a[j]
    ...
}
```

Therefore, virtual machine will throw an exception if the class does not implement `Comparable` interface.



### 6.1.2 Properties of Interfaces

1. You can never use `new`  operator to instantiate an interface
2. Interface variables can still be declared.
3. `instanceof` can be used to check whtether an object implements an interface.
4. Interfaces can be extended.
5. Methods in an interface are automatically `public`, fields are always `public static final`.
6. Classes can implement *multiple* interfaces.



### 6.1.3 Interfaces and Abstract Classes

Interfaces are often used instread of abstract classes when a class wants to "extends different classes". They actually successfully reach the purpose of multiple inheritence.



### 6.1.4 Static Methods



### 6.1.5 Default Methods

You can supply default implementation for any interface method. You must tag such a method with the `default` modifier.

```java
public interface Comparable<T>
{
	default int compareTo(T other) { return 0; }
}
```



This is often used when programmers who implement this interface only need to override some of the methods provided in the interface. A default method can call other methods.

An important use for default method is interface evolution. (See p299)



### 6.1.6 Resolving Default Method Conflicts

Question: What happens if the exact same method is defined as a default method in one interface and then again as a method of a superclass or another interface?

Answer:

1. Superclasses win. If a superclass provides a concrete method, default methods with the same name and parameter types are simply ignored.
2. Interfaces clash. If a superinterface provides a default method, and another interface supplies a method with the same name and parameter types (default or not), then you must resolve the conflict by overriding that method.



## 6.2 Examples of Interfaces

### 6.2.1 Interfaces and Callbacks

A common pattern in programming is called callback pattern. In this pattern, you specify the action that occur when a button is clicked or a menu item is selected.



### 6.2.2 The Comparator Interface

If we are to compare two String objects by their length, we cannot have the `String` class implement the `compareTo` method in two ways and we cannot modify `String` class.

Comparator is used to deal with this kind of situation. Comparator is an instance of a class that implements `Comparator` interface.

```java
public interface Comparator<T>
{
	int compare(T first, T second);
}
```



With this, we can define a class that implements `Comparator<String>`. 

```java
class LengthComparator implements Comparaotr<String>
{
	public int compare(String first, String second)
    {
    	return first.length() - second.length();
    }
}
```



To actually do the comparison, we need to make an instance:

```java
Comparator<String> comp = new LengthComparator();
if (comp.compare(words[i], words[j]) < 0)
{
    ...;
}
```



Note the the `compare` method is called on the comparator object, not the string itself. Also, since this method is non-static, we need to instantiate the class with an object to call this method.

`Arrays.sort()` method can take two parameters, where the first one is an array of objects and second one is an instance of a cloass that implements `Comparable` interface.



### 6.2.3 Object Cloning

Steps:

1. Decide whether to use `clone` method for your class

2. Implement `Clonable` interface and redefine the `clone` method with a `public` modifier.

   - Escpecially, if the default `clone` method is not good enough, provide deep copy on your own.

     ```java
     class MyClass implements Clonable
     {
     	@Override
     	MyClass clone() throws CloneNotSupportedException
         {
         	MyClass copy = (MyClass) super.clone();
         	// make deep copy for subobjects if necessary
         	return copy;
         }
     }
     ```


Note that the exception needs to be handled manually because `clone` method is inherited from `Object` class instead of overriding a method in `Clonable` interface.