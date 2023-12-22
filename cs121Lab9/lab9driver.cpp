/**********************
* Programmer: Merveilles
* Professor: Streller
* Course: CS121
* FileName: lab9driver
* Description: 
* Date written: 11/14/23
***********************/


#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

// Function to calculate weekly gross pay
//
// Function Name: calculateWeeklyGrossPay
//
//Purpose: To calculate the weekly gross pay
//
//Input parameters: Variable of type struct (Employee emp)
//
//Output parameters: None
//
//Return: gross pay of type double
//////////////////////////////////

double calculateWeeklyGrossPay(Employee emp) {
    return emp.pay_rate * emp.hrs_worked;
}

// Function to determine salutation based on gender
//
// Function Name: getSalutation
//
//Purpose: to determine salutation based on gender
//
//Input parameters: Variable of type struct (Employee emp)
//
//Output parameters: None
//
//Return: string "Mr. " or "Ms. "
//////////////////////////////////

string getSalutation(Employee emp) {
    if (emp.gender == 'm' || emp.gender == 'M') {
        return "Mr. ";
    }
    else if (emp.gender == 'f' || emp.gender == 'F') {
        return "Ms. ";
    }
    else {
        return "";
    }
}

/*
Enter employee 1 details:
First Name: Merveilles
Last Name: Katumba
Gender (m/f): m
ID Number: 4532332
Pay Rate: 19.5
Hours Worked: 25
Mr. Merveilles's weekly gross pay: $487.5
Enter employee 2 details:
First Name: Rufus
Last Name: Mumwena
Gender (m/f): m
ID Number: 21
Pay Rate: 21.5
Hours Worked: 20
Mr. Rufus's weekly gross pay: $430
Enter employee 3 details:
First Name: Jenny
Last Name: Kapinga
Gender (m/f): F
ID Number: 45332224
Pay Rate: 22
Hours Worked: 18.5
Ms. Jenny's weekly gross pay: $407
*/
