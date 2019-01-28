#include <cstdio>
#include <cstring>

int main()
{
  char *ptr;
  char delimiters[5] = ", ";
  char input[80] = "Hi, today is another training of ACM.";
  ptr = strtok(input, delimiters);
  while (ptr != NULL)
  {
    printf("%s", ptr);
    ptr = strtok(NULL, delimiters);
  }
}
