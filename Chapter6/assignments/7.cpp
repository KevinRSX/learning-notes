#include <iostream>
#include <cctype>
#include <string>

int main()
{
	using namespace std;
	cout << "Enter words, q to quit:\n";
	string word;
	int vowels = 0, consonants = 0, others = 0;
	while (cin >> word&&word != "q")
	{
		if (isalpha(word[0]))
		{
			switch (word[0])
			{
			case 'a': vowels++;
				break;
			case 'A': vowels++;
				break;
			case 'e': vowels++;
				break;
			case 'E': vowels++;
				break;
			case 'i': vowels++;
				break;
			case 'I': vowels++;
				break;
			case 'o': vowels++;
				break;
			case 'O': vowels++;
				break;
			case 'u': vowels++;
				break;
			case 'U': vowels++;
				break;
			default:consonants++;
			}
		}
		else
			others++;
	}

	cout << vowels << "words beginning with vowels\n";
	cout << consonants << "words beginning with consonants\n";
	cout << others << "others\n";
	return 0;
}