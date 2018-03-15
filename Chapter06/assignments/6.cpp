#include <iostream>
#include <string>

struct donationInfo
{
	std::string patron;
	double amount;
};

int main()
{
	using namespace std;
	int n;
	cout << "Enter the number of patrons: ";
	cin >> n;
	cin.get();
	donationInfo * patronList = new donationInfo[n];

	//get info
	for (int i = 0; i < n; i++)
	{
		cout << "Enter information: patron #" << i + 1 << ":\n";
		cout << "Name: ";
		getline(cin, patronList[i].patron);
		cout << "Donation amount: ";
		cin >> patronList[i].amount;
		cin.get();
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