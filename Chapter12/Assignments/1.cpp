#include <iostream>
class Cow
{
private:
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;
};

Cow::Cow()
{
	strcpy(name, "shabi");
	hobby = new char[3];
	strcpy(hobby, "td");
	weight = 200.0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	strcpy(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow::Cow(const Cow & c)
{
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(name, c.name);
	strcpy(hobby, c.hobby);
}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c)
		return *this;
	else
	{
		delete[] hobby;
		strcpy(name, c.name);
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
		weight = c.weight;
		return *this;
	}
}

void Cow::ShowCow() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Hobby: " << hobby << std::endl;
	std::cout << "Weight: " << weight << std::endl;
	std::cout << std::endl;
}

int main()
{
	using namespace std;
	Cow a;
	a.ShowCow();
	Cow b("newbee", "fuck", 2000.0);
	b.ShowCow();
	a = b;
	a.ShowCow();
}