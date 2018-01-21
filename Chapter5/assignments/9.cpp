#include <iostream>
#include <string>

int main()
{
	using namespace std;
	cout << "Enter words (to stop, enter the word done): \n";
	string word;
	cin >> word;
	cin.get();
	int count = 0;
	while (word != "done")
	{
		cin >> word;
		cin.get();
		count++;
	}
	cout << "You entered a total of " << count << " words.\n";
	return 0;
}