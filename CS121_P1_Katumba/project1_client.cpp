#include "project1.h"
// Main Function

int main()
{
    double FederalIncomeTax = 0; // Federal Income Tax
    double TaxableIncome = 0; // Taxable Income
    double GrossIncome = 0; // Gross Income
    string ssn;
    char choice = 'Y'; // checks whether user wants to continue the loop or not
    do
    { // start of main loop

        isValidSSN(); // function call to get the social security number

        GrossIncome = InputGrossIncome(); // function call to get gross income

        TaxableIncome = ComputeTaxableIncome(GrossIncome); // function call to get taxable income

        FederalIncomeTax = ComputeFederalIncomeTax(GrossIncome); // function call to calculate federal income tax

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