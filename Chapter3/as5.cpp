#include <iostream>
int main()
{
	using namespace std;
	long long world, us;
	cout << "Enter the world's population: ";
	cin >> world;
	cout << "Enter the population of the US: ";
	cin >> us;

	double proportion = 100 * (double(us) / double(world));
	cout << "The population of the US is " << proportion << "% of the world population." << endl;
	return 0;
}