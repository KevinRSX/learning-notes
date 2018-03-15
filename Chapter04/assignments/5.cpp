#include <iostream>

struct CandyBar
{
	char label[20];
	float weight;
	int calories;
};

int main()
{
	using namespace std;
	CandyBar snack = { "Mocha Munch", 2.3, 350 };
	cout << snack.label << endl << snack.weight << endl << snack.calories << endl;
	return 0;
}