#ifndef _PROJECT1_H
#define _PROJECT1_H

#include <iostream> // For cout and cin
#include <string> // For cin.getline()
#include <iomanip> // For setprecision()

using namespace std;

// Function Prototypes

// isValidSSN checks for a valid Social Security Number
void isValidSSN();

// GetGrossIncome gets the gross income and returns it.
double InputGrossIncome();

// GetTaxableIncome gets the taxable income and returns it.
double ComputeTaxableIncome
(double x); // IN: value of gross income

// GetFederalIncomeTax calculates the federal income tax using the taxable income.
double ComputeFederalIncomeTax
(double x); // IN: value of gross income

// DisplayValues displays the SocialSecurityNumber, the gross income, the taxable income and the federal income tax due.
void DisplayValues
(string a,  // IN: string of Social Security Number
    double x,  // IN: value of gross income
    double y,  // IN: value of taxable income
    double z); // IN: value of federal income tax due

#endif // !_PROJECT1!_H

