
///////////////////////////////////////////////////////////////////////////////
//
// File Name         : project3_driver.cpp
//
// This program gets two Binary Numbers from the User and either Adds or
// Multiplies them.
//
// Programmer        : B.J. Streller AND Moe Myint Maung
//
// Date Written      : in the past
//
// Date Last Revised : 12/17/2023
//
///////////////////////////////////////////////////////////////////////////////



#include<iostream>
using namespace::std;

#include "binNum.h"
#include "misc_ops.h"


int main()
{
	char RepeatCheck = 'N'; // main loop checker

	do {

		BinNum FirstNum; // the first binary number
		BinNum SecondNum; // the second binary number
		BinNum Result; // the result

		int check; // contains the return value of addOrMultiply function

		prompt(1);
		cin >> FirstNum;
		cout << endl;

		prompt(2);
		cin >> SecondNum;
		cout << endl;

		check = addOrMultiply();

		if (check == 1) {
			cout << "Adding the two numbers..." << endl << endl;
			Result = FirstNum + SecondNum;

			cout << "In binary form: \t" << FirstNum << " + " << SecondNum 
				<< " = " << Result << endl;
			cout << "In base 10 form: \t" << FirstNum.bin2Base10() << " + " 
				<< SecondNum.bin2Base10() << " = " << Result.bin2Base10() << endl << endl;
		}
		else if (check == 2) {
			cout << "Multiplying the two numbers..." << endl << endl;
			Result = FirstNum * SecondNum;

			cout << "In binary form: \t" << FirstNum << " * " << SecondNum
				<< " = " << Result << endl;
			cout << "In base 10 form: \t" << FirstNum.bin2Base10() << " * "
				<< SecondNum.bin2Base10() << " = " << Result.bin2Base10() << endl << endl;
		}
		cout << "Would you like to restart? (Y/N): " << endl;
		cin >> RepeatCheck;
		cout << endl;

	} while (RepeatCheck == 'Y');

	cout << "Showing output. Press Enter to Exit.";
	cin.ignore();
	char ch = getchar();

	return 0;
}