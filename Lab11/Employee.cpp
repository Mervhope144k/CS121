//////////////////////////////////////////////////////////////////////////////////////////
//
// File Name         : lab11.h
//
// This program uses a user defined struct called employee and uses it to get the gender 
// of the employee, their first and last name, their pay rate and 
// how many hours they have worked. It finally outputs their full name and their gross pay.
// 
// This file contains the implimentaion of the function info
// 
// Programmer        : Merveilles Biende Katumba
//
// Date Written      : 11/10/2023
//
// Date Last Revised : 12/12/2023
//
////////////////////////////////////////////////////////////////////////////////////////////

#include "Employee.h"

//////////////////////////////// info ///////////////////////////////
//
// Function name: info
//
// Purpose: sets given info based on gender
//
//
// Input parameters: in - the employee
//
// Output parameters: none
//
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////
void info(Employee e){
	if (e.gender == 'm' || e.gender == 'M'){
		cout << "Mr. " << e.f_name << " " << e.l_name
			<< ", your gross pay is " << e.gross_pay << endl;
	}
	else if (e.gender == 'f' || e.gender == 'F'){
		cout << "Ms. " << e.f_name << " " << e.l_name
			<< ", your gross pay is " << e.gross_pay << endl;
	}
}