#include <iostream>
int bs(int * a, int n, int key,int & c);

int main()
{
	using namespace std;
	int a[6];
	cout << "Enter the element in the array:\n";
	for (int i = 0; i < 6; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 5; j > i; j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	cout << "The sorted array is: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i << ", ";
	}
	cout << a[6] << endl;
	cout << "Enter the number to search:\n";
	int n;
	cin >> n;
	int ite = 0;
	
	int position = bs(a, 5, n, ite);
	if (position == -1)
	{
		cout << "The number does not exist in the array.\n";
	}
	else
	{
		cout << "The position of the element is: " << position << endl;
	}
	cout << ite << "iterations used.\n";
	return 0;
}

int bs(int * a, int n, int key,int & c)
{
	int mid, front = 0, back = n - 1;
	while (front <= back)
	{
		mid = (front + back) / 2;
		if (a[mid] == key)
			return mid;
		if (a[mid]<key)
			front = mid + 1;
		else back = mid - 1;
		c++;
	}
	return -1;
}