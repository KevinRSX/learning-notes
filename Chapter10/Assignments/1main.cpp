#include <iostream>
#include "1.h"

int main()
{
	Account me("Kevin", 22012412, 300.0);
	me.show();
	Account you("Pity", 34100021, 18.0);
	you.show();
	me.deposit(700.0);
	you.checkout(20.0);
	me.show();
	you.show();
}