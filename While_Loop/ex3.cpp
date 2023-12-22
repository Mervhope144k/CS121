#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
const string SENTINEL = "-1";
int main() {
	string name;
	int numOfVolunteers;
	int numOfBoxesSold;
	int totalNumOfBoxesSold;
	double costOfOneBox;

	cout << fixed << showpoint << setprecision(2);
	cout << "enter each volunteer's name and the number of boxes " << endl
	<< "sold by each volunteer, ending with -1: " << endl;
	totalNumOfBoxesSold = 0;
	numOfVolunteers = 0;
	cin >> name;
	while (name != SENTINEL) {
		cin >> numOfBoxesSold;
		totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
		numOfVolunteers++;
		cin >> name;
	}
	cout << endl;
	cout << "The total number of boxes sold: " << totalNumOfBoxesSold << endl;
	cout << "enter the cost of one box: ";
	cin >> costOfOneBox;
	cout << endl;
	cout << "The total money made by sellin cookies: $" << totalNumOfBoxesSold * costOfOneBox << endl;
	if (numOfVolunteers != 0)
		cout << "the average number of boxes sold by each volunteer: " << totalNumOfBoxesSold / numOfVolunteers << endl;
	else
		cout << "No input." << endl;
	return 0;
}