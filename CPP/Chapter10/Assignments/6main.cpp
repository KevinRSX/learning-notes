#include <iostream>
#include "6.h"

int main(int argc, const char * argv[])
{
	Move rob1(7, 8);
	Move rob2(3, 4);
	rob1.showmove();
	rob2.showmove();
	rob1 = rob1.add(rob2);
	rob1.showmove();
	rob2.reset(2, 6);
	rob2.showmove();
	return 0;
}