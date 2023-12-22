#ifndef _BANKING_H
#define _BANKING_H
#include <iostream>		        //cin, cout, cerr, endl
#include <string>		        //for string
#include <fstream>		        //for fstream
#include <stdlib.h>		        //for exit
#include <iomanip>				// For formatting output
#include <stdio.h>              // For keeping the terminal screen open
#include <ctype.h>              // for isdigit
using namespace std;


struct Account	                //struct account type to hold customer info
{
	int acct_num;		        //customer account number
	string name;		        //customer's name
	double acct_bal;		    //customer's account balance
    double beginning_balance;   //customer's account balance
    double ending_balance;      //balance of activities excluded initial balance
    double total_deposits;      //total amount deposited
    int num_deposits;           //number of deposits
    double total_withdrawals;   //total amount withdrwan
    int num_withdrawals;        //number of withdraws


     //Constructor to initialize variables
    Account() : acct_num(0), acct_bal(0.0), beginning_balance(0.0), ending_balance(0.0),
        total_deposits(0.0), num_deposits(0), total_withdrawals(0.0), num_withdrawals(0) {}
    friend ostream& operator<<(ostream& outs, const Account& emp) {
        outs << emp.acct_num << " " << emp.acct_bal << " " << " " << emp.name << " " << emp.beginning_balance 
             << " " << emp.ending_balance << " " << emp.total_deposits << " " << emp.total_deposits 
             << " " << emp.num_deposits << " " << emp.num_withdrawals << " " << emp.total_withdrawals << endl;
        return outs;
    }
    friend istream& operator>>(istream& ins, Account& emp) {
        ins >> emp.acct_bal >> emp.acct_num >> emp.name >> emp.beginning_balance >> emp.ending_balance 
            >> emp.num_deposits >> emp.num_withdrawals >> emp.total_deposits >> emp.total_withdrawals;
        return ins;
    }
    Account& operator=(const Account& init) {
        if (this == &init)
            return *this;
        acct_bal = init.acct_bal;
        name = init.name;
        acct_num = init.acct_num;
        beginning_balance = init.beginning_balance;
        ending_balance = init.ending_balance;
        total_deposits = init.total_deposits;
        num_deposits = init.num_deposits;
        total_withdrawals = init.total_withdrawals;
        num_withdrawals = init.num_withdrawals;
        return *this;
    }
};
//function prototypes
string getFileName();	//prompt for complete file name
void openFile(string nameOf, fstream& inOut);	//open file for reading
#endif //_!BANKING!_