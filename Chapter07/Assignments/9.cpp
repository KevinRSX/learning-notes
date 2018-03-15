#include <iostream>
#include <cstring>

using namespace std;
const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(student * ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	int i = 0;
	while (i < n)
	{
		cout << "Enter student #" << i + 1 << "'s name: ";
		cin.getline(pa[i].fullname, SLEN);
		if (!strcmp(pa[i].fullname, ""))
			break;
		cout << "Enter studnet #" << i + 1 << "'s hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Enter student #" << i + 1 << "'s ooplevel: ";
		cin >> pa[i].ooplevel;
		cin.get();
		i++;
	}
	return i;
}

void display1(student st)
{
	cout << "Name: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "OOPlevel: " << st.ooplevel << endl;
}

void display2(student * ps)
{
	cout << "Name: " << ps->fullname << endl;
	cout << "Hobby: " << ps->hobby << endl;
	cout << "OOPlevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Name: " << pa->fullname << endl;
		cout << "Hobby: " << pa->hobby << endl;
		cout << "OOPlevel: " << pa->ooplevel << endl;
	}
}