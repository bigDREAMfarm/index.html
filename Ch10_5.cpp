//Test Program
#include <iostream>
#include <iomanip>
#include <string>
#include "dayType.h"

using namespace std;

int main()
{
	dayType myday("Mon", 2 , 2);

	cout << "My Day: ------------------" << endl;
	myday.print();
	cout << endl;



	system("pause");
	return 0;
}