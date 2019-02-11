#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
  char ch;
  string s = "";
  ch = getchar();
  while (ch != '.')
  {
    s += ch;
    ch = getchar();
  }
  cout << "Your input is: " << s << endl;
}
