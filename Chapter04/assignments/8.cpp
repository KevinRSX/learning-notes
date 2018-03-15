#include <iostream>
struct pizza
{
	char name[20];
	double diameter;
	double weight;
};

int main()
{
	using namespace std;
	pizza * hut = new pizza;
	cout << "Enter the diameter, then name, then weight: " << endl;
	cin >> hut->diameter;
	cin.get();
	cin.getline(hut->name, 20);
	cin >> hut->weight;
	cout << endl << hut->name << endl << hut->diameter << endl << hut->weight << endl;

	return 0;
}