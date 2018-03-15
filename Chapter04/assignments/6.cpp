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
	CandyBar snack[3];
	snack[0] = { "Fuck you", 13.0, 250 };
	cout << snack[0].label << endl << snack[0].weight << endl << snack[0].calories << endl;
	return 0;
}