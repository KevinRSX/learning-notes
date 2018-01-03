#include <iostream>
int main()
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	cout << "Add one to the character code:" << endl;
	ch++;
	i = ch;
	cout << "The ASCII code for " << ch << " is " << i << endl;

	//using the cout.put() member function to display a char
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);

	//using cout.put() to display a constant
	cout.put('!');

	cout << "\n\nDone." << endl;

	return 0;
}