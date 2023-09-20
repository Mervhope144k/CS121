/*
*Description: Given length in inches, this program converts the equivalent output in feet and remaining inches.
*Programmer: Merveilles
*Date: 
*/

#include <iostream>

using namespace std;

int main()
{
	int inches; // variable to store total length in inches
	cout << "Enter total inches and press Enter: ";
	cin >> inches;
	cout << endl;
	cout << inches << " inch (es) "; // output the value of inches and the equal sign
	cout << inches / 12 << " feet (foot) and "; // output maxinum number of feet (foot)
	cout << inches % 12 << " inch (es) " << endl; // output remaning inch (es)

	return 0;
}
