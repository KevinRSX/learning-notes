#include <iostream>

const int Size = 5;

template <typename T>
T max5(T arr[]);

int main(int argc, char * argv[])
{
	using namespace std;
	int a[Size] = { 2,6,4,8,1 };
	cout << "max5(int a[]) = " << max5(a) << endl;
	double b[Size] = { 1.23,10.1,11.2,6.4,2.26 };
	cout << "max5(double b[]) = " << max5(b) << endl;
	return 0;
}


template <typename T>
T max5(T arr[])
{
	T max = arr[0];
	for (int i = 1; i < Size; i++)
		max = arr[i] > max ? arr[i] : max;
	return max;
}