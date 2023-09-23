// Example: scientific and fixed

#include <iostream>

using namespace std;

int main()
{
	double const HOURS = 35.45;
	double const RATE = 15.00;
	double const TOLERANCE = 0.01000;

	cout << "hours = " << HOURS << ", rate = " << RATE
		<< ", pay = " << HOURS * RATE
		<< ", tolerance = " << TOLERANCE << endl << endl;

	cout << scientific;
	cout << "scientific notation: " << endl;
	cout << "hours = " << HOURS << ", rate = " << RATE
		<< ", pay = " << HOURS * RATE
		<< ", tolerance = " << TOLERANCE << endl << endl;

	cout << fixed;
	cout << "Fixed decimal notation: " << endl;
	cout << "hours = " << HOURS << ", rate = " << RATE
		<< ", pay = " << HOURS * RATE
		<< ", tolerance = " << TOLERANCE << endl << endl;

	return 0;
}