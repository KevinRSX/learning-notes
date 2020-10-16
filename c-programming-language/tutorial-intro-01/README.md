# 1 A Tutorial Introduction

## 1.1 Getting Started

- A C program consists of functions and variables
- Functions contains statements
- Function can be given any names, but `main()` is special: your program begins executing at the beginning of `main()`
  - A program must have a `main()` somewhere
- `#include <stdio.h>` tells the compiler to include information about the standard input/output library
- Arguments are used to communicate data between functions
- Statements in the functions are enclosed in braces `{}`



Study this statement:

```c
printf("hello, world\n");
```

- A function is called by naming it, followed by a paranthesized list of arguments
  - In this example the argument is `"hello, world\n"`
- A sequence of characters in double quotes, like `"hello, world\n"`, is called a character string or string constant
- `\n` is the notation for the newline character
  - must use `\n` to include a newline character in the `printf` argument
  - `printf` does not supply a newline automatically



## 1.2 Variables and Arithmetic Expressions

- Declaration and assignment of variables
- Types of variables: size are machine-dependent
- While loop
- `%` as an argument of `printf`

- Implicit type conversion
  - Both sides are integer: integer operation
  - One side integer and one side lost: convert integer to floating point before the operation
- Conversion specifications: `%d`, `%f`, `%6f`, `%.1f`, `%6.1f`

