#include <iostream>

int main()
{
	using namespace std;
	char ch;
	cin.get(ch);
	int count = 0;
	while (!cin.fail())
	{
		cout << ch;
		count++;
		cin.get(ch);
	}
	cout << count << " characters read.\n";
	return 0;
}