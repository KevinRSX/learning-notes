#include <iostream>
#include "2.h"

int main(int argc, const char *argv[])
{
	Person one;
	one.show();
	one.FormalShow();
	Person two("Smythecraft");
	two.show();
	two.FormalShow();
	Person three("Dimwiddy", "Sam");
	three.show();
	three.FormalShow();
	return 0;
}