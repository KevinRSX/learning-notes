#include <iostream>
#include <string>
#include <fstream>

struct donationInfo
{
	std::string patron;
	double amount;
};

int main()
{
	using namespace std;
	int n;
	ifstream fin;
	fin.open("patrons.txt");	// a txt named "patrons.txt" should be created with example inputs in the correct
	//format before running this program.
	fin >> n;
	fin.get();
	donationInfo * patronList = new donationInfo[n];

	//get info
	for (int i = 0; i < n; i++)
	{
		getline(fin, patronList[i].patron);
		fin >> patronList[i].amount;
		fin.get();
	}

	//print info
	cout << "Grand patrons:\n";
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (patronList[i].amount > 10000)
		{
			count++;
			cout << patronList[i].patron << '\t' << patronList[i].amount << endl;
		}
	}
	if (count == 0)
		cout << "None\n";
	count = 0;

	cout << "Patrons:\n";
	for (int i = 0; i < n; i++)
	{
		if (patronList[i].amount < 10000)
		{
			count++;
			cout << patronList[i].patron << '\t' << patronList[i].amount << endl;
		}
	}
	if (count == 0)
		cout << "None\n";

	delete[] patronList;

	return 0;
}