// Program to see how the get() works

#include <iostream>
using namespace std;

int main()
{
	char ch1, ch2;
	int num;

	cout << "Enter the values to be store in ch1, ch2 and num "
		<< "separate by a blank: ";
	cin.get(ch1);
	cin.get(ch2); 
	cin >> num;
	cout << "The value of ch1 is: " << ch1 << endl;
	cout << "The value of ch2 is: " << ch2 << endl;
	cout << "The value of num is: " << num << endl;

	return 0;
}