// Input failure and the clear()

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	int age, weight = 0;
	double height = 0.0;

	cout << "Line 14:, Enter name, age, weight, and "
		<< "height: ";
	cin >> name >> age >> weight >> height;
	cout << endl;

	cout << "Line 19: Name: " << name << endl;
	cout << "Line 20: Age: " << age << endl;
	cout << "Line 21: Weight: " << weight << endl;
	cout << "Line 22: Height: " << height << endl;

	cin.clear();      // Restore input stream

	cin.ignore(200, '\n');    // Clear the buffer

	cout << "\nLine 28: Enter name, age, weight, "
		<< "and height: ";

	cin >> name >> age >> weight >> height;
	cout << endl;

	cout << "Line 34: Name: " << name << endl;
	cout << "Line 35: Age: " << age << endl;
	cout << "Line 36: Weight: " << weight << endl;
	cout << "Line 37: Height: " << height << endl;

	return 0;

}