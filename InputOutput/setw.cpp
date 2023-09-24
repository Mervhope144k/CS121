// Example: This example illustrates how the function setw works

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int miles = 245;
	int speed = 55;
	double hours = 35.45;
	double error = 3.7564;

	cout << fixed << showpoint;
	cout << "12345678901234567890123456789" << endl;

	cout << setw(5) << miles << endl;

	cout << setprecision(2);

	cout << setw(5) << miles << setw(5) << speed
		<< setw(6) << hours
		<< setw(7) << error << endl << endl;

	cout << setw(5) << speed << setw(5) << miles
		<< setw(4) << hours
		<< setw(7) << error << endl << endl;

	cout << setw(2) << miles << setw(6) << hours
		<< setw(7) << error << endl << endl;

	cout << setw(2) << miles
		<< setw(7) << "error"
		<< error << endl;

	return 0;
}