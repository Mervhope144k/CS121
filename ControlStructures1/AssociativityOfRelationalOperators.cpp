// Program with Logic errors

#include<iostream>

using namespace std;

int main()
{
	int num;

	cout << "Enter an integer: ";
	cin >> num;
	cout << endl;

	//if (0 <= num <= 10)		// this expression is valid but logically wrong
	if (0 << num && num <= 10)
		cout << num << " is witnin 0 and 10." << endl;

	else
		cout << num << " is not within 0 and 10." << endl;

	return 0;
}