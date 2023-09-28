// Example of a Logic Error, from a correct code and the solution

/*
#include <iostream>

using namespace std;

int main()
{
	int fahrenheit;
	int celsius;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahrenheit;
	cout << endl;

	celsius = 5 / 9 * (fahrenheit - 32);

	cout << fahrenheit << " degree F = "
		<< celsius << " degree C. " << endl;

	return 0;
}
*/

/*#include <iostream>

using namespace std;

int main()
{
	int fahrenheit;
	int celsius;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahrenheit;
	cout << endl;

	cout << "5 / 9 = " << 5 / 9  // Here is error, result is 0
		<< "; fahrenheit - 32 = "
		<< fahrenheit - 32 << endl;

	celsius = 5 / 9 * (fahrenheit - 32); // 0 * int = 0

	cout << fahrenheit << " degree F = "
		<< celsius << " degree C. " << endl;

	return 0;
}
*/


#include <iostream>

using namespace std;

int main()
{
	int fahrenheit;
	int celsius;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahrenheit;
	cout << endl;

	celsius = static_cast<int> (5.0 / 9 * (fahrenheit - 32));

	cout << fahrenheit << " degree F = "
		<< celsius << " degree C. " << endl;

	return 0;
}