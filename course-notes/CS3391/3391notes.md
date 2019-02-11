# 1 Week 1

## 1.1 I/O Tricks

- Totally 5 places, packed with leading zeroes

  ```c++
  print("%5d\n", 7);		// outputs 00007
  ```

- `scanf()` can do some simple parsing.

  ```c++
  scanf("(%d, %d)", &x, &y);
  ```

  It returns the number of items it gets from the input or EOF if there is an error.

  The return value of EOF is -1, whose two's compliment is all one, so the following trick is often used:

  ```c++
  while (~scanf("%d%%d", &a, &b))
  {
      ...
  }
  ```

- Getting a single character

  ```c++
  ch = getchar();
  ```

- Reading lines in C

  ```c++
  char[20] buffer;
  fgets(buffer, len, stdin);
  ```

- File I/O

  ```C++
  FILE *fp = fopen("input.txt", "r");
  // ... operations
  fclose(fp);
  ```

  ```c++
  fprintf(fp, "%d", num);	// output to file
  fscanf(fp, "%d", &num);	// read input from file
  ch = fgetc(fp);			// read a character from file
  fgets(buffer, len, fp);	// read a string from file
  ```

- Output to string

  ```c++
  sprintf(buffer, "%d", N);	// print int N to string buffer
  scanf(buffer, "%d", &N);	// to read an int from string
  
  // advanced use
  sprintf(dest, "%s", src);	// string copy
  sprintf(dest, "%s%s", src1, src2);	// string concatenation
  sscanf(buf, "%d", &Int_Var);
  sscanf(buf, "%d", &Float_Var);	// act in the same behavior as atoi() and atol()
  ```



## 1.2 Arithmetic Functions and Bitwise Operations

- Note that the result of -11 % 3 is -2 in both visual studio and gcc.

- Usage of Bitwise operations

  ```c++
  // checking parity
  if (x & 1) printf("x is odd");
  
  // check for divisibility of 2's power
  if (x & 7) printf("x is not divisible by 8"); // last three digits are not 000
  
  // Round down to the nearest multiple of 2's power
  x = 27;
  y = 27 & (~7);		// erase the last three digits
  
  // quick multiplication and division
  x <<= 2;
  x >>= 2;
  ```

  

  

##  1.3 Count Prime

Sieve of Eratos. Explanation is omitted. This algorithm is $O(nlogn)$

```c++
void countprime(int n)
{
    memset(prime, -1, sizeof(prime));	// set array values as -1
    for (int i = 2; i < n; i++)
    {
        if (prime[j])
        {
            for (int j = i + i; j < n; j += i)
        	{
            	prime[j] = 0;		// j is not prime
        	}
        }
    }
}
```

We can improve it by filtering a number only by its biggest factor so that each number is traversed only once. 

For example, the number 16 will only be filtered by 8.

```c++
void getprime(int n)
{
    bool flag[N];
    memset(flag, true, sizeof(flag));
    int cnt = 0;	// total number found prime now
    for (int i = 2; i <= n; i++)
    {
        if (flag[i])
            prime[++cnt] = i;	// if a number is not filtered, it is prime
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            flag[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}
```

$Proof$:

We assume $i=p\cdot r$, when we execute the break, $i\text{ mod }p=0$. At this point, $x_1=p\cdot r\cdot p$ is filtered. However, when we consider another number $x_2 = p\cdot r\cdot q$, where $q>p$, note that $x_2 = q\cdot r\cdot p$. So the factor is bigger in this case.

For example, $16=8\times 2=4\times 2\times 4$. If we want to further factorize $8\times 3=24$, we know that $24=4\times 3\times 2=4\times 2\times 3$, that is it has a larger factor 12. Therefore, we need to break here.

See [wk1_get_prime.cpp](wk1_get_prime.cpp) for code details.



# 2 Week 2

## 2.1 String Parsing

Consider this problem: We have a string that represents a sentence: "Hi, today is another training of ACM." How can we break it into words? i.e., "Hi", "today", "is", "another", "training", "of", "ACM."?

There is a function `strtok()`  in `string.h` library that can accomplish this task easily. We may try to implement it on our own first.

```c++
#include <cstdio>

char input[80] = "Hi, today is another training of ACM.";
char *p = input, *cur = input;

int main()
{
  while (*p != '\0')
  {
    if (*p == ',' || *p == ' ')
    {
      *p = '\0';
      if (*cur != '\0')
      {
        printf("%s\n", cur);
      }
      cur = ++p;
    }
    else p++;
  }
  printf("%s\n", cur);
  return 0;
}
```



See <http://www.cplusplus.com/reference/cstring/strtok/> for details of how to use this function. Here we provide a sample use.



## 2.2 Recursion

### 2.2.1 Example 1 $n\choose r $

Problem: Given n characters a, b, c, d,..., we want to choose r characters and display them in order. For example, if we choose 3 characters from "abcde", we should output:

```
abc abd abe acd ace ade bcd bce bde cde
```



Solution1: We have $r$ positions. It can be divided into subproblems of selecting one char from $n$ chars for position $i$ and select one char from $n - 1$ chars for position $i + 1$.

A rough algorithm:

```pseudocode
combination(set, subset, r)
{
    if (r == 0)	// the subset contains enough elements
    {
        print elements in subset
        return;
    }
    while (set is not empty)
    {
        move the first element from set to subset
        combination(set, subset, r - 1)
        remove the last element in subset
    }
}
```



Solution2: We have $r$ positions. Select one character from $n$ characters for each position.

```pseudocode
combination(set, subset, r)
{
    if (r == 0)	// when the subset contains enough elements
    {
        print elements in subset
        return
    }
    if (set is empty)
    {
        return
    }
    move the first element from set to subset
    combination(set, subset, r - 1)
    remove the last element in subset
    combination(set, subset, r)
}
```



Codes are available [here](wk2_combination.cpp).



### 2.2.2 Tower of Hanoi

The objective is to move n disks from the source pole A to the destination pole C with the help of temporary  pole B. We can write a program to show the whole process. It will be extremely tedious to do it without recursion. Recursion make this problem significantly easy.

Steps:

1. Move the smallest n - 1 disks from A to B with the help of C
2. Move the largest disk from A to C with the help of B
3. Move the smallest n - 1 disks from B to C with the help of A

Implementation

```c++
void Hanoi(int n, char source, char dest, char temp)
{
  if (n == 0) return;
  Hanoi(n - 1, source, temp, dest);
  cout << "Disk no. " << n << " is moved from " << source << " to " << dest\
    << " with the help of " << temp << endl;
  Hanoi(n - 1, temp, dest, source);
}
```



