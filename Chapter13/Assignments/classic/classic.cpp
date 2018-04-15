#include <iostream>
#include "classic.h"

using std::cout;
using std::endl;

Cd::Cd()
{
	performers = new char[5];
	std::strcpy(performers, "None");
	label = new char[5];
	std::strcpy(performers, "None");
	selections = 0;
	playtime = 0.0;
}

Cd::Cd(char * s1, char * s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	std::strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char[strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

void Cd::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
	cout << endl;
}

Cd & Cd::operator=(const Cd & d)
{
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

Classic::Classic() :Cd()
{
	important = new char[5];
	std::strcpy(important, "None");
}

Classic::Classic(char * s1, char * s2, int n, double x, char * im) :Cd(s1, s2, n, x)
{
	important = new char[strlen(im) + 1];
	std::strcpy(important, im);
}

Classic::Classic(const Cd & d, char * im) :Cd(d)
{
	important = new char[strlen(im) + 1];
	std::strcpy(important, im);
}

Classic::Classic(const Classic & cl):Cd(cl)
{
	important = new char[strlen(cl.important) + 1];
	std::strcpy(important, cl.important);
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Important classic musics: " << important << endl;
	cout << endl;
}

Classic & Classic::operator=(const Classic & cl)
{
	if (this == &cl)
		return *this;
	Cd::operator=(cl);
	delete[] important;
	important = new char[strlen(cl.important) + 1];
	std::strcpy(important, cl.important);
	return *this;
}

Classic::~Classic()
{
	delete[] important;
}