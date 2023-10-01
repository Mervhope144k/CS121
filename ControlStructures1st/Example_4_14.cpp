// Program to determine if the additonal charges are applicable on
// a suitcase

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double suitcaseDimension;
	double suitcaseWeight;
	double additionalCharges = 0.0;

	cout << fixed << showpoint << setprecision(2);
	cout << "Enter suitcase dimensions "
		<< "(length + width + depth) in inches: ";
	cin >> suitcaseDimension;
	cout << endl;

	cout << "Enter suitcase weigth in pounds: ";
	cin >> suitcaseWeight;
	cout << endl;

	if (suitcaseDimension > 108 || suitcaseWeight > 50)
		additionalCharges = 50.00;

	cout << "Additional suitcase charges: $"
		<< additionalCharges << endl;

	return 0;
}