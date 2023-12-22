//*********************************************************************************
//
//	Programmer: Merveilles Katumba Biende
//	Instructor: B.J. Streller
//	Course: CS 121
//	Date: 10/28/2023
//	Program Name: project1_driver.cpp
//	Program File: Project1
//	Purpose: This program calculates the federal income tax
//           The taxable income and return to the console
//           The social security number, the federal income tax
//           The Gross income and the taxable income
//			 of an unmarried single tax payer.
//
//*********************************************************************************

#include "project1.h"


//*********************************************************************************
//  Function Name: isValidSSN
//	Purpose: checks validity of Social Security Number.
//	Parameters: None
//	    Output: invalid Social Security Number if the ssn entered fail the test
//	Return Value: None
//	Global Variables Used: ssn
//*********************************************************************************

void isValidSSN()
{
    string ssn;     //string to store the social security
    const int VALIDSSNLENGTH = 9; // valid social security length
    int SizeOfSSN = 0; // initialized size of string ssn
    bool Loop = true; // loop condition initialized to true

    // prompts the user to enter the SSN and test its validity
    while (Loop)
    { // start while loop
        // prompts the user for the SSN
        cout << "Please enter your Social Security Number: " << endl;
        cin >> ssn;

        bool Error = false; // error-checking variable initialized to false
        SizeOfSSN = ssn.length();   // get the lenght of ssn

        // checks if the SSN only contains digits
        for (int i = 0; i < VALIDSSNLENGTH; i++)
        { // start of digits-only checking loop

            if (ssn[i] < '0' || ssn[i] > '9')
            { // start of condition
                Error = true;
                break;
            } // end of condition          
        } // end of digits-only checking loop
        // check for valid ssn length and non all-zeroes.
        if (SizeOfSSN != VALIDSSNLENGTH || ssn == "000000000")
        { // start of condition
            Error = true;
        } // end of condition

        if (Error != false)
        { // start of ErrorCheck
            cout << "Invalid Social Security Number!\n"
                << "Enter a SSN of exactly 9 digits,"
                << "without whitespaces nor special characters!" << endl;
            //Loop = false; // 
        }
        else
            Loop = false; // condition to end get out of while loop
    } // end while loop
} // end isValidSSN

//*********************************************************************************
//  Function Name: InputGrossIncome
//	Purpose: Gets the Gross Income
//	Parameters: None
//	    Output: invalid value if value entered fail the test
//	Return Value: grossIncome
//*********************************************************************************

double InputGrossIncome()
{

    // asks for user input and loops if the value is less than 0
    bool error = true; // bool value to control while loop
    double grossIncome = 0; // local variable that stores the value of the user input

    while (error == true)
    { // start while loop
        // prompt user to enter gross income
        cout << "\nPlease enter your gross income: \n";
        cin >> grossIncome;

        if (grossIncome > 0)
        {
            error = false;
        }
        else
        {
            cout << "Invalid value!\n";
        }
    } // end while loop

    return grossIncome; // returns the value entered by the user

} // end GetGrossIncome

//*********************************************************************************
//  Function Name: ComputeTaxableIncome
//	Purpose: Compute the Taxable Income based on the user gross Income.
//	Parameters: double GrossIncome
//	    Input: GrossIncome 
//      Output: TaxableIncome
//	Return Value: taxIncome
//*********************************************************************************

double ComputeTaxableIncome(double GrossIncome)
{
    double taxIncome = 0; // local variable to declare taxable income

    if (GrossIncome >= 0 && GrossIncome < 24650)
    { // start of condition
        taxIncome = GrossIncome;
    }
    else
        if (GrossIncome >= 24650 && GrossIncome < 59750)
        {
            taxIncome = GrossIncome - 24650;
        }
        else
            if (GrossIncome >= 59750 && GrossIncome < 124650)
            {
                taxIncome = GrossIncome - 59750;
            }
            else
                if (GrossIncome >= 124650 && GrossIncome < 271050)
                {
                    taxIncome = GrossIncome - 124650;
                }
                else
                {
                    taxIncome = GrossIncome - 271050;
                } // end of condition

    return taxIncome; // returns the taxable income after it is computed

} // end  ComputeTaxableIncome
//*********************************************************************************
//  Function Name: ComputeFederalIncomeTax
//	Purpose: Compute the Federal Income tax given the gross income and their relationship.
//	Parameters: double GrossIncome
//	    Input: GrossIncome
//      Output: FederalIncomeTax
//	Return Value: fedincTax
//*********************************************************************************

double ComputeFederalIncomeTax(double GrossIncome)
{
    double FedIncTax = 0; // local variable to store and set the federal income tax to 0

    if (GrossIncome >= 0 && GrossIncome < 24650)
    { // start of condition
        FedIncTax = 0.15 * GrossIncome;
    }
    else
        if (GrossIncome >= 24650 && GrossIncome < 59750)
        {
            FedIncTax = 3697.5 + (0.28 * (GrossIncome - 24650));
        }
        else
            if (GrossIncome >= 59750 && GrossIncome < 124650)
            {
                FedIncTax = 13525.5 + (0.31 * (GrossIncome - 59750));
            }
            else
                if (GrossIncome >= 124650 && GrossIncome < 271050)
                {
                    FedIncTax = 33644.5 + (0.36 * (GrossIncome - 124650));
                }
                else
                {
                    FedIncTax = 86348.5 + (0.396 * (GrossIncome - 271050));
                } // end of condition

    return FedIncTax; // returns the federal income tax after it is calculated

} // end ComputeFederalIncomeTax

//*********************************************************************************
//  Function Name: DisplayValues
//	Purpose: Displays the social security number, gross income, taxable income and federal
//           income tax due.
//	Parameters: string ssn, double GrossIncome, double TaxableIncome, double FederalIncomeTax
//	    Input: ssn (SocialSecurityNumber array)
//             GrossIncome (GrossIncome double)
//             TaxableIncome (TaxableIncome double)
//             FederalIncomeTax (FederalIncomeTax double)
//      Output: Display of the values
//	Return Value: none
//*********************************************************************************

void DisplayValues(string ssn, double GrossIncome, double TaxableIncome, double FederalIncomeTax)
{

    // outputs the values requested by the main function (SSN, gross income, taxable income, federal income tax)
    // note: the values are outputted in 2 decimal places and in fixed notation

    cout << "\nYour social security number is " << ssn << ". \n"; \
        cout << fixed << setprecision(2) << "Your gross income is " << GrossIncome << " $. \n";
    cout << "Your taxable income is " << TaxableIncome << " $. \n";
    cout << "Your federal income tax due is " << FederalIncomeTax << " $. \n\n";

} // end DisplayValues

/////OUTPUT/////
/*
Please enter your Social Security Number:
111111111

Please enter your gross income:
40000

Your social security number is .
Your gross income is 40000.00 $.
Your taxable income is 15350.00 $.
Your federal income tax due is 7995.50 $.

Would you like to start over? (Y/N):
*/