///////////////////////////////////////////////////////////////////////////////
//
// File Name         : misc_ops.cpp
//
// Purpose           : contains implementations of supportive funtions to run the program
//
// Programmer        : M.B Katumba
//
// Date Written      : 12/14/2023
//
// Date Last Revised : 12/18/2023
//
///////////////////////////////////////////////////////////////////////////////

#include "misc_ops.h"
#include "binNum.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////
//
// Function name: greet()
//
// Purpose: Display a welcome message to the console
//
// Input parameters: none
//			        					 
// Output parameters: none
//
// Return Value: void 
//
///////////////////////////////////////////////////////////////////////////////

void greet() {
    cout << "Welcome to the Binary Number Calculator!" << std::endl;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: displayMenu()
//
// Purpose: display the operation options to the console and prompt the user to choose
//
// Input parameters: none
//			        					 
// Output parameters: none
//
// Return Value: void 
//
///////////////////////////////////////////////////////////////////////////////
void displayMenu() {
    cout << "Choose an operation:" << std::endl;
    cout << "+ : Addition" << std::endl;
    cout << "* : Multiplication" << std::endl;
    cout << "Enter your choice (+ or *): ";
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: getUserOperation()
//
// Purpose: propmt user to enter an operation (+ or *), takes the opration to be used
//
// Input parameters: none
//			        					 
// Output parameters: none
//
// Return Value: char which is the opration 
//
///////////////////////////////////////////////////////////////////////////////
char getUserOperation() {
    char operation;
    cin >> operation;
    return operation;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: getUserBinaryInput()
//
// Purpose: prompt user to enter the 4 bits binary number, takes it in the stream
//
// Input parameters: none
//			        					 
// Output parameters: none
//
// Return Value: BinNum
//
///////////////////////////////////////////////////////////////////////////////
BinNum getUserBinaryInput(){
    cout << "WARNING: MUST BE A VALID 4 BITS BINARY NUMBER " << endl;
    BinNum InputBinNum;
    cin >> InputBinNum;
    return InputBinNum;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: performOperation
//
// Purpose: perform the operation entered by the user on the binary numbers entered
//
// Input parameters: binNum1 -> binary number entered by user of type class BinNum
//                   binNum2 -> binary number entered by user of type class BinNum
//                   operation -> opration entered by user of type character
//			        					 
// Output parameters: result of type class BinNum and its corresponding decimal value
//
// Return Value: void 
//
///////////////////////////////////////////////////////////////////////////////
void performOperation(BinNum& binNum1, BinNum& binNum2, char operation) {
    switch (operation) {
    case '+': {
        BinNum result = binNum1 + binNum2;
        cout << "In binary form: " << binNum1 << " + " << binNum2 
                  << " = " << result << std::endl;
        cout << "In base 10 form: " << binNum1.bin2Base10() << " + " 
                  << binNum2.bin2Base10() << " = " << result.bin2Base10() << std::endl;
        break;
    }
    case '*': {
        BinNum result = binNum1 * binNum2;
        cout << "In binary form: " << binNum1 << " * " 
                  << binNum2 << " = " << result << std::endl;
        cout << "In base 10 form: " << binNum1.bin2Base10() << " * " 
                  << binNum2.bin2Base10() << " = " << result.bin2Base10() << std::endl;
        break;
    }
    default:
        cout << "Invalid operation!" << std::endl;
        break;
    }
}