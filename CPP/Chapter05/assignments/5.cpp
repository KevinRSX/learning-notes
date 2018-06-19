#include <iostream>

int main()
{
	using namespace std;
	const char * months[] = { "January","February","March","April","May","June","July","August",
	"September","October","Novemnber","December" };
	int sales[12], sum=0;
	for (int i = 0; i < 12; i++)
	{
		cin >> sales[i];
		cout << sales[i] << " book(s) sold in " << months[i] << endl;
		sum += sales[i];
	}
	cout << endl << sum << " in total.\n";
}