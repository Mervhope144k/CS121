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

#include <iostream> // For cout and cin
#include <string> // For cin.getline()
#include <iomanip> // For setprecision()

using namespace std;

// Variables
const int VALIDSSNLENGTH = 9; // valid social security length
string ssn;
double GrossIncome = 0; // Gross Income
double TaxableIncome = 0; // Taxable Income
double FederalIncomeTax = 0; // Federal Income Tax

// Function Prototypes

// isValidSSN checks for a valid Social Security Number
void isValidSSN();

// GetGrossIncome gets the gross income and returns it.
double InputGrossIncome();

// GetTaxableIncome gets the taxable income and returns it.
double ComputeTaxableIncome
(double y); // IN: value of gross income

// GetFederalIncomeTax calculates the federal income tax using the taxable income.
double ComputeFederalIncomeTax
(double x); // IN: value of taxable income

// DisplayValues displays the SocialSecurityNumber, the gross income, the taxable income and the federal income tax due.
void DisplayValues
(string a,  // IN: string of Social Security Number
    double b,  // IN: value of gross income
    double c,  // IN: value of taxable income
    double d); // IN: value of federal income tax due

// Main Function

int main()
{
    char choice = 'Y'; // checks whether user wants to continue the loop or not
    do
    { // start of main loop

        isValidSSN(); // function call to get the social security number

        GrossIncome = InputGrossIncome(); // function call to get gross income

        TaxableIncome = ComputeTaxableIncome(GrossIncome); // function call to get taxable income

        FederalIncomeTax = ComputeFederalIncomeTax(TaxableIncome); // function call to calculate federal income tax

        DisplayValues(ssn, GrossIncome, TaxableIncome, FederalIncomeTax); // function call to display the values

        // prompts the user for choice to start over
        cout << "Would you like to start over? (Y/N): " << endl;
        cin >> choice;
        cout << endl;

        cin.ignore(); // ignores the ans character

    } while (choice == 'Y' || choice == 'y'); // end of main loop

    // Shows the output so that the program doesn't exit immediately after it runs.
    cout << "Press Enter to Exit." << endl;
    cin.ignore();
    char ch = getchar();

} // end main

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
    bool error = true; // value that keeps the while loop running
    double grossIncome; // local variable that stores the value of the user input

    while (error == true)
    { // start of loop
        grossIncome = 0; // grossIncome is set to 0

        // console output and input
        cout << "\nPlease enter your gross income: \n";
        cin >> grossIncome;

        if (grossIncome > 0)
        { // start of condition
            error = false;
        } // end of condition
        else
        {
            cout << "Invalid value!\n";
        }
    } // end of loop

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

double ComputeFederalIncomeTax(double taxIncome)
{
    double FedIncTax = 0; // local variable to store and set the federal income tax to 0

    if (taxIncome >= 0 && taxIncome < 24650)
    { // start of condition
        FedIncTax = 0.15 * taxIncome;
    }
    else
        if (taxIncome >= 24650 && taxIncome < 59750)
        {
            FedIncTax = 3697.5 + (0.28 * (taxIncome - 24.650));
        }
        else
            if (taxIncome >= 59750 && taxIncome < 124650)
            {
                FedIncTax = 13525.5 + (0.31 * (taxIncome - 59.750));
            }
            else
                if (taxIncome >= 124650 && taxIncome < 271050)
                {
                    FedIncTax = 33644.5 + (0.36 * (taxIncome - 124.650));
                }
                else
                {
                    FedIncTax = 86348.5 + (0.396 * (taxIncome - 271.050));
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
000000000
Invalid Social Security Number!
Enter a SSN of exactly 9 digits, without whitespaces nor special characters
Please enter your Social Security Number:
1234567%
Invalid Social Security Number!
Enter a SSN of exactly 9 digits, without whitespaces nor special characters
Please enter your Social Security Number:
43
Invalid Social Security Number!
Enter a SSN of exactly 9 digits, without whitespaces nor special characters
Please enter your Social Security Number:
000000001

Please enter your gross income:
24649

Your social security number is 000000001.
Your gross income is 24649.00 $.
Your taxable income is 24649.00 $.
Your federal income tax due is 3697.35 $.

Would you like to start over? (Y/N):
y

Please enter your Social Security Number:
123456789

Please enter your gross income:
59749

Your social security number is 123456789.
Your gross income is 59749.00 $.
Your taxable income is 35099.00 $.
Your federal income tax due is 20427.22 $.

Would you like to start over? (Y/N):
y

Please enter your Social Security Number:
435467890

Please enter your gross income:
124649

Your social security number is 435467890.
Your gross income is 124649.00 $.
Your taxable income is 64899.00 $.
Your federal income tax due is 52166.69 $.

Would you like to start over? (Y/N):
y

Please enter your Social Security Number:
543218765

Please enter your gross income:
271049

Your social security number is 543218765.
Your gross income is 271049.00 $.
Your taxable income is 146399.00 $.
Your federal income tax due is 131222.14 $.

Would you like to start over? (Y/N):
y

Please enter your Social Security Number:
543217654

Please enter your gross income:
271100

Your social security number is 543217654.
Your gross income is 271100.00 $.
Your taxable income is 50.00 $.
Your federal income tax due is 193704.10 $.

Would you like to start over? (Y/N):
n

Press Enter to Exit.
*/