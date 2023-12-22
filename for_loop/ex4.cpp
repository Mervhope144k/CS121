//Program: Counts zeros, odds, and evens

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 10;
int main() {
	int counter, number, zeros = 0, odds = 0, evens = 0;
	cout << "enter " << N << " Integers, " << "positive, negative or zeros." << endl;
	cout << "The numbers you entered are:" << endl;
	for (counter = 1; counter <= N; counter++) {
		cin >> number;
		cout << number << " ";
		switch (number % 2) {
		case 0:
			evens++;
			if (number == 0)
				zeros++;
			break;
		case 1:
		case -1:
			odds++;
		}
	}
	cout << endl;
	cout << "There are " << evens << " evens, " << "Which includes " << zeros << " zeros." << endl;
	cout << "The number of odd numbers is: " << odds << endl;
	return 0;
}