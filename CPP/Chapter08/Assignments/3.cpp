#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void showupper(string &k);

int main(int argc, char * argv[])
{
	string in;
	cout << "Enter a string (q to quit): ";
	getline(cin, in);
	while (in != "q")
	{
		showupper(in);
		cout << "Next string (q to quit): ";
		getline(cin, in);
	}
	cout << "Bye." << endl;
	return 0;
}

void showupper(string &k)
{
	int i = 0;
	while (k[i])
	//NOTE: DO NOT use length method of string here because passing by reference will not give you the length
	{
		k[i] = toupper(k[i]);
		i++;
	}
	cout << k << endl;
}