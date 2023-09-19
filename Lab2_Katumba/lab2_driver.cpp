//*******************************************************************
//
//File Name:           lab2_driver.cpp
//
//This program computes the selling price of an object given its retail
//price,discount and tax. 
//
//Programmer:          B.J.Streller AND Merveilles B Katumba
//
//Date Written:        11 September 2023 
//
//Date Last Revised:   18 September 2023
//
//*******************************************************************



#include <iostream>		//need for cin.cout
#include <iomanip>		//need for setprecision, setf, etc
#include <stdio.h>		//need for getchar()
using namespace std;


int main()
{

	//DECLARATIONS

	double  retail_price,
		discount_rate,
		price_discount,
		tax_amount,
		sale_price,
		total_price;
	const double sales_tax = 0.0825; //constant for sales tax rate of 8.25%

	//INPUT
	cout << " please enter the price of the item: " << endl;
	cin >> retail_price;
	cout << "please enter the discount rate ( as a decimal - no % please ): "
		<< endl;
	cin >> discount_rate;

	// TODO : PROCESS (CALCULATE)
	price_discount = discount_rate * retail_price;
	sale_price = retail_price - price_discount;
	tax_amount = sale_price * sales_tax;
	total_price = sale_price + tax_amount;

	//OUTPUT
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout << setprecision(2);
	cout << sale_price << endl; // cout statements TODO
	cout << total_price << endl; // cout statements TODO
	cout.unsetf(ios::showpoint);


	// these 3 lines hold 
	// the command window open
	cout << "enter any key to continue: \n";
	cin.ignore();
	char ch = getchar();
	return 0;
}

/*
 please enter the price of the item:
550
please enter the discount rate ( as a decimal - no % please ):
0.25
412.50
446.53
enter any key to continue:
*/