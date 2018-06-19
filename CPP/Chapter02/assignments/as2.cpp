#include <iostream>
int ltoy(int);

int main()
{
	using namespace std;
	cout << "Enter a distance (long): ";
	int distanceLong;
	cin >> distanceLong;

	int distanceYard;
	distanceYard = ltoy(distanceLong);
	cout << "Equals to " << distanceYard << " yard." << endl;

	return 0;
}

int ltoy(int len)
{
	return len * 220;
}