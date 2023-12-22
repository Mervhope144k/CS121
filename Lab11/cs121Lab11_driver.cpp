//////////////////////////////////////////////////////////////////////////////////////////
//
// File Name         : cs121lab9.cpp
//
// This program uses a user defined struct called employee and uses it to get the gender 
// of the employee, their first and last name, their ID, and thier pay rate and 
// how many hours they have worked. It finally outputs their ID, full name and their gross pay.
// 
// This file contains the main program
// 
// Programmer        : Merveilles Biende Katumba
//
// Date Written      : 11/10/2023
//
// Date Last Revised : 12/12/2023
//
////////////////////////////////////////////////////////////////////////////////////////////


#include "Employee.h"


int main(){
	const int SIZE = 3;			//constant size of 3
	Employee employ[3];			//array of 3 employees

	cout << "Hello." << endl;

    for (int i = 0; i < SIZE ; i++){	//requesting info from user
		cout << "Employee " << i+1 << " , Please enter your first and last name, your gender, your hours worked,";
		cout << " and your hourly rate:" << endl;

		employ[i].setEmployee(employ[i]);
		info(employ[i]);
    }
	cout << "\n\n\n  Press any key to exit" << endl;
	cin.ignore();
	char ch = getchar();

	return 0;  //end of program 
}


//******************************SAMPLE OUTPUT**************************************//
//Hello.
//Employee 1, Please enter your firstand last name, your gender, your hours worked, and your hourly rate :
//Merveilles Katumba m 43 23
//Mr.Merveilles Katumba, your gross pay is 989
//Employee 2, Please enter your firstand last name, your gender, your hours worked, and your hourly rate :
//Jenny Kapinga f 45 18
//Ms.Jenny Kapinga, your gross pay is 810
//Employee 3, Please enter your firstand last name, your gender, your hours worked, and your hourly rate :
//Urbain Mushimbi m 45 15
//Mr.Urbain Mushimbi, your gross pay is 675



//Press any key to exit

//*****************************************************************************************//


