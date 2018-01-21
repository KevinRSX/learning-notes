#include <iostream>
#include <ctime>

int main()
{
	using namespace std;

	cout << "Enter the waiting time\n";
	int sec;
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC;
	clock_t start = clock();
	cout << "Starting!\n\a";
	while (delay > clock() - start);
	cout << "Nice Job!\a\n";

	return 0;
}