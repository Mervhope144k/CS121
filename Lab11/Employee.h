//////////////////////////////////////////////////////////////////////////////////////////
//
// File Name         : lab11.h
//
// This program uses a user defined struct called employee and uses it to get the gender 
// of the employee, their first and last name, their ID, and thier pay rate and 
// how many hours they have worked. It finally outputs their ID, full name and their gross pay.
// 
// This file contains the struct Employee and the programs function prototype
// 
// Programmer        : Merveilles Biende Katumba
//
// Date Written      : 11/10/2023
//
// Date Last Revised : 12/12/2023
//
////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EMPLOYEE.H_
#define _EMPLOYEE_H 


#include <iostream>						     // need for cin, cout
#include <string>                           // need for strings   
#include <stdio.h>                         // need for getchar()

using namespace std;


struct Employee{
	//Employee fields
	string f_name;								//first name of employee
	string l_name;								//last name of emploee
	char gender;								//gender of employee
	int id_num, pay_rate, hrs_worked;			//id number, pay rate and how many hours worked of employee
	double gross_pay;							//gross pay of employee

	void setEmployee(Employee& e){
		cin >> e;
		e.gross_pay = e.pay_rate * e.hrs_worked;
		cout << endl;
	}

	
	
	friend ostream& operator<<(ostream& outs, const Employee& e){	//overloading insertion operator
		outs << "Hello" << e.gender << "." << e.f_name << " " << e.l_name << endl;
		outs << "Your gross pay is " << "$" << e.gross_pay;
		return outs;
	}
	friend istream& operator >> (istream& ins, Employee& e){	//overloading expraction operator
		ins >> e.f_name >> e.l_name >> e.gender >>
			e.pay_rate >> e.hrs_worked;
		return ins;
	}

	Employee& operator = (const Employee& init){
		if (this == &init)
			return*this;  // avoiding self assignment
		gender = init.gender;
		f_name = init.f_name;
		l_name = init.l_name;
		id_num = init.id_num;
		pay_rate = init.pay_rate;
		hrs_worked = init.hrs_worked;
		gross_pay = init.gross_pay;

		return*this;
	}

};

//function prototype
void info(Employee e);		//function to print info


#endif 
