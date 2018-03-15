#include <iostream>

struct CandyBar
{
	char * band;
	double weight;
	int heat;
};

void assign(CandyBar &cd, char * c = "Millennium Munch", double wei = 2.85, int hea = 350);
void show(CandyBar &cd);

int main()
{
	using namespace std;
	CandyBar telford;
	assign(telford, "lubsub", 4.6, 177);
	show(telford);
	cout << endl;
	assign(telford);
	show(telford);
	return 0;
}

void assign(CandyBar &cd, char * c, double wei, int hea)
{
	cd.band = c;
	cd.weight = wei;
	cd.heat = hea;
}

void show(CandyBar &cd)
{
	using namespace std;
	cout << "Band: " << cd.band << endl;
	cout << "Weight: " << cd.weight << endl;
	cout << "Heat: " << cd.heat << endl;
}