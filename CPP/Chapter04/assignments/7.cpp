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
	pizza hut;
	cin.getline(hut.name, 20);
	cin >> hut.diameter;
	cin >> hut.weight;
	cout << hut.name << endl << hut.diameter << endl << hut.weight << endl;

	return 0;
}