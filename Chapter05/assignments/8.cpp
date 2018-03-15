#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	cout << "Enter words (to stop, enter the word done): \n";
	char word[15];
	cin >> word;
	cin.get();
	int count = 0;
	while (strcmp(word, "done"))
	{
		cin >> word;
		cin.get();
		count++;
	}
	cout << "You entered a total of " << count << " words.\n";
	return 0;
}