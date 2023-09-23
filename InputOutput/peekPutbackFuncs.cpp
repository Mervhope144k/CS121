// Functions peek() and putback()

#include <iostream>
using namespace std;

int main()
{
	char ch;
	int num;

	cout << "Line 10: Enter a string: ";
	cin.get(ch);
	cout << endl;
	cout << "Line 13: After first cin.get(ch); "
		<< "ch = " << ch << endl;

	cin.get(ch);
	cout << "Line 17: After second cin.get(ch); "
		<< "ch = " << ch << endl;

	cin.putback(ch);
	cin.get(ch);
	cout << "Line 22: After putback and then "
		<< "cin.get(ch); ch = " << ch << endl;
	num = cin.peek();
	cout << "Line 25: After cin.peek(); num = "
		<< num << endl;

	cin.get(ch);
	cout << "Line 29: After cin.get(ch); ch = "
		<< ch << endl;

	return 0;
}