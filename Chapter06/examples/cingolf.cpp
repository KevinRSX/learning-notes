#include <iostream>
const int MAX = 5;
int main()
{
	using namespace std;
	//get data
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << MAX << " rounds.\n";
	int i;
	int golf[MAX];
	for (i = 0; i < MAX; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin>>golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Enter a number: ";
		}
	}
	double total = 0.0;
	for (i = 0; i < MAX; i++)
	{
		total += golf[i];
	}
	cout << total / i << " = average score " << MAX << " rounds.\n";
	return 0;
}