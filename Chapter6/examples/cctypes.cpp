#include <iostream>
#include <cctype>

int main()
{
	using namespace std;
	cout << "Enter text for analysis, and type @ to terminate input:\n";
	char ch;
	int whitespace = 0, digits = 0, chars = 0;
	int punct = 0, others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))	// is it an alphabetic character?
			chars++;
		else if (isspace(ch))	//is it a white space character?
			whitespace++;
		else if (isdigit(ch))	//is it a digit?
			digits++;
		else if (ispunct(ch))	//is it a punctuation?
			punct++;
		else
			others++;
		cin.get(ch);
	}
	cout << chars << " letters, " << whitespace << " whitespace, "
		<< digits << " digits, " << punct << " punctuations, "
		<< others << " others.\n";
	return 0;
}