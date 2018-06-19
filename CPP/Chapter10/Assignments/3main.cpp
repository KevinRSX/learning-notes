#include <iostream>
#include "3.h"

int main(int argc, const char * argv[])
{
	Golf a;
	a.show();
	Golf b("LEUNG Chiu Wai", 6);
	b.show();
	a.setgolf();
	a.show();
	return 0;
}