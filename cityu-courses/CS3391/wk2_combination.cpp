#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

void combination(char *chset, vector<char> selected, int r, int start)
{
  if (r == 0)
  {
    for (vector<char>::iterator it = selected.begin(); it != selected.end();\
     it++)
    {
      putchar(*it);
    }
    putchar(' ');
    return;
  }

  for (int i = start; i < strlen(chset); i++)
  {
    selected.push_back(chset[i]);
    combination(chset, selected, r - 1, i + 1);
    // when i >= 3 is passed as parameter at the point r = 3, the whole
    // function will do nothing
    selected.erase(selected.end() - 1);
  }
}

int main()
{
  char chset[] = "abcde";
  vector<char> v;
  combination(chset, v, 3, 0);
  printf("\n");
  return 0;
}
