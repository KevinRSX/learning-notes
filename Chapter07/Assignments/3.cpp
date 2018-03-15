#include <iostream>

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show_value(box a);
void calc_volume(box * a);

int main()
{
	using namespace std;
	box lap;
	cout << "Enter maker: ";
	cin.getline(lap.maker, 40);
	cout << "Enter height: ";
	cin >> lap.height;
	cout << "Enter length: ";
	cin >> lap.length;
	cout << "Enter width: ";
	cin >> lap.width;
	show_value(lap);
	calc_volume(&lap);
	return 0;
}

void show_value(box a)
{
	using namespace std;
	cout << "Maker: " << a.maker << endl;
	cout << "Height: " << a.height << endl;
	cout << "Width: " << a.width << endl;
	cout << "Length: " << a.length << endl;
}

void calc_volume(box * a)
{
	using namespace std;
	a->volume = a->width*a->height*a->length;
	cout << "Average: " << a->volume << endl;
}