#include <iostream>
using namespace std;

void Hanoi(int n, char source, char dest, char temp)
{
  if (n == 0) return;
  Hanoi(n - 1, source, temp, dest);
  cout << "Disk no. " << n << " is moved from " << source << " to " << dest\
    << " with the help of " << temp << endl;
  Hanoi(n - 1, temp, dest, source);
}


int main()
{
  Hanoi(4, 'A', 'C', 'B');
  return 0;
}
