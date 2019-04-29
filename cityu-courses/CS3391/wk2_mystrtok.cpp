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
