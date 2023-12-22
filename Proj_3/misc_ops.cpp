///////////////////////////////////////////////////////////////////////////////
//
// File Name         : misc_ops.cpp
//
// This file contains the miscellaneous function definitions of the project.
//
// Programmer        : Moe Myint Maung
//
// Date Written      : 12/17/2023
//
// Date Last Revised : 12/17/2023
//
///////////////////////////////////////////////////////////////////////////////

#include "misc_ops.h" // header file
#include <iostream> // for cout and cin
#include <string> // for string data type
#include <stdio.h> // for cin.ignore()

///////////////////////////////////////////////////////////////////////////////
//
// Function name: prompt
//
// Purpose: prompts the user according to the input parameter
//
// Input parameters: int x
//					 
// Output parameters: none
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////

void prompt(int x) {
	if (x == 1)
		cout << "Please enter the first binary number:" << endl;
	else cout << "Please enter the second binary number:" << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: addOrMultiply
//
// Purpose: asks the user whether he or she wants to add or multiply the two
//			binary numbers
//
// Input parameters: none
//					 
// Output parameters: none
//
// Return Value: returnValue variable that determines addition or multiplication
//				in the main function
//
///////////////////////////////////////////////////////////////////////////////

int addOrMultiply() {
	string Check = "";
	int returnValue = 0;
	bool Response = false;

	do {
		cout << "Would you like to Add or Multiply the two numbers?" << endl;
		cout << "(Input 'Add' or 'Multiply')" << endl;
		cin >> Check;
		cout << endl;
		if (Check == "Add") {
			returnValue = 1;
			Response = true;
		}
		else if (Check == "Multiply") {
			returnValue = 2;
			Response = true;
		}
		else {
			cout << "Please enter again!" << endl;
		}
	} while (Response == false);
	return returnValue;
}