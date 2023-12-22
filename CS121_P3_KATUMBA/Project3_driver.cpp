///////////////////////////////////////////////////////////////////////////////
//
// File Name         : Project3_driver.cpp
//
// Purpose           : Contain the functions definitions of supportive functions
//
// Programmer        : M.B Katumba
//
// Date Written      : 12/14/2023
//
// Date Last Revised : 12/18/2023
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "binNum.h"
#include "misc_ops.h"
using namespace std;

int main() {
    char userChoice;
    
    do {
        greet();

        BinNum binNum1, binNum2;
        char operation;

        do {
            displayMenu();
            cout << endl;
            operation = getUserOperation();
            if (operation == '*') {
                cout << "The operation being performed is: Multiplication and the sign is " << operation << endl;
            }
            else if (operation == '+')
                cout << "The operation being performed is: Addition and the sign is " << operation << endl;
            else
                break;
            cout << endl;
           
            if (operation == '+' || operation == '*') {
                cout << "Enter the first Binary Number " << endl;
                binNum1 = getUserBinaryInput();
                cout << "The first Binary number is: " << binNum1 << endl << endl;
                cout << "Enter the second Binary Number " << endl;
                binNum2 = getUserBinaryInput();
                cout << "The second Binary number is: " << binNum2 << endl << endl;
                performOperation(binNum1, binNum2, operation);
            }
            
        } while (operation != '+' && operation != '*');

        cout << "Do you want to leave the program? (y/n): ";
        cin >> userChoice;
    } while (userChoice == 'n' || userChoice == 'N');

    cout << "Exiting the program. Goodbye!" << std::endl;
    cout << "Showing output. Press Enter to Exit.";
    cin.ignore();
    char ch = getchar();
    return 0;
}

///////////////////////CONSOLE OUTPUT//////////////////////////
/*
Welcome to the Binary Number Calculator!
Choose an operation :
+: Addition
* : Multiplication
Enter your choice(+or *) :
    +
    The operation being performed is : Addition and the sign is +

    Enter the first Binary Number
    WARNING : MUST BE A VALID 4 BITS BINARY NUMBER
    1100
    The first Binary number is : 1100

    Enter the second Binary Number
    WARNING : MUST BE A VALID 4 BITS BINARY NUMBER
    1111
    The second Binary number is : 1111

    In binary form : 1100 + 1111 = 1011
    In base 10 form : 12 + 15 = 11
    Do you want to leave the program ? (y / n) : n
    Welcome to the Binary Number Calculator!
    Choose an operation :
+: Addition
* : Multiplication
Enter your choice(+or *) :
    *
    The operation being performed is : Multiplication and the sign is *

    Enter the first Binary Number
    WARNING : MUST BE A VALID 4 BITS BINARY NUMBER
    1101
    The first Binary number is : 1101

    Enter the second Binary Number
    WARNING : MUST BE A VALID 4 BITS BINARY NUMBER
    1110
    The second Binary number is : 1110

    In binary form : 1101 * 1110 = 0110
    In base 10 form : 13 * 14 = 6
    Do you want to leave the program ? (y / n) : y
    Exiting the program.Goodbye!
    Showing output.Press Enter to Exit.
*/
