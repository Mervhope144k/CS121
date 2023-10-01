// Program: Compare two integer numbers

#include <iostream>

using namespace std;

int main()
{
	int num1, num2;

	cout << "Enter the two numbers: ";
	cin >> num1 >> num2;
	cout << "The numbers are: " << num1 << " and "
		<< num2 << endl;

	if (num1 > num2)
		cout << "The larger number is: " << num1 << endl;
	else
		if (num2 > num1)
			cout << "The larger number is: " << num2 << endl;
		else
			cout << " The two numbers are equal" << endl;

	return 0;
}