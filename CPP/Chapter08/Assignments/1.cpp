#include <iostream>

void print(char * str, int n = 1);

int main()
{
	using namespace std;
	char a[] = "Deal";
	print("Fuck you");
	print("All right", 2);
	print(a, 3);
	return 0;
}

void print(char * str, int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
		cout << str << endl;
}