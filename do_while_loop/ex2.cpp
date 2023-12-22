//Program: Divisibility test by 3 and 9
#include <iostream>
using namespace std;
int main() {
	int num, sum, temp;
	cout << "enter a positive integer: ";
	cin >> num;
	cout << endl;
	temp = num;
	sum = 0;
	do {
		sum += num % 10;
		num /= 10;
	} while (num > 0);
	cout << "The sum of the digits = " << sum << endl;
	if (sum % 9 == 0)
		cout << temp << " is div by 3 and 9" << endl;
	else if (sum % 3 == 0)
		cout << temp << " is div by 3, but not 9" << endl;
	else
		cout << temp << " is not div by 3 or 9" << endl;
	return 0;
}