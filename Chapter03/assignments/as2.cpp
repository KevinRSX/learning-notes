#include <iostream>
int main()
{
	using namespace std;
	int foot, inch, pound;
	cout << "How tall are you?\n__ Feet\b\b\b\b\b\b\b";
	cin >> foot;
	cout << "__ inches\b\b\b\b\b\b\b\b\b";
	cin >> inch;
	cout << "How heavy are you?\n___ pounds\b\b\b\b\b\b\b\b\b\b";
	cin >> pound;

	const float m_per_inch = 0.0254;
	const float pounds_per_kg = 2.2;
	const int inches_per_foot = 12;
	float height = (foot * inches_per_foot + inch)*m_per_inch;
	float weight = pound / pounds_per_kg;

	float bmi = weight / (height*height);

	cout << "Your BMI is: " << bmi << endl;

	return 0;
}