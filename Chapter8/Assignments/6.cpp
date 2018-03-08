#include <iostream>

template <typename T>
T maxn(T arr[],int n);
template <> char * maxn(char * arr[], int n);

int main(int argc, char * argv[])
{
	using namespace std;
	int a[6] = { 2,6,4,8,1,5 };
	cout << "maxn(int a[],6) = " << maxn(a, 6) << endl;
	double b[4] = { 1.23,11.2,6.4,2.26 };
	cout << "maxn(double b[],4) = " << maxn(b, 4) << endl;
	char * c[4] = { "DIU","La","Ma","DingYingSheung" };		//¡°ŒÅÄÇÂè£¬¶¥Ó²ÉÏ¡± -- Ô¬³ç»À
	cout << "maxn(char * c[],4) = " << maxn(c, 4) << endl;
	return 0;
}


template <typename T>
T maxn(T arr[],int n)
{
	T max = arr[0];
	for (int i = 1; i < n; i++)
		max = arr[i] > max ? arr[i] : max;
	return max;
}

template <> char * maxn(char * arr[], int n)
{
	char * address = arr[0];
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		int j = 0;
		while (arr[i][j++]);
		address = j > max ? arr[i] : address;
		max = j > max ? j : max;
	}
	return address;
}