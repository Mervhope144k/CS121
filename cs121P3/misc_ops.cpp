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
// Date Last Revised : 12/16/2023
//
///////////////////////////////////////////////////////////////////////////////

#include "misc_ops.h"
#include "binNum.h"
#include <limits>

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
    std::cout << "Welcome to the Binary Number Calculator!" << std::endl;
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
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "+ : Addition" << std::endl;
    std::cout << "* : Multiplication" << std::endl;
    std::cout << "Enter your choice (+ or *): ";
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
    std::cin >> operation;
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
int getUserBinaryInput() {
    int num;
    std::cout << "Enter a 4-bit binary number: ";
    std::cin >> num;

    // Validate the entered binary number
    while (num < 0 || num > 15) {
        std::cout << "Invalid input! Please enter a 4-bit binary number (0-15): ";
        std::cin >> num;
    }
    return num;
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
void performOperation(BinNum& binNum1, BinNum& binNum2, char operation){
    switch (operation) {
    case '+': {
        BinNum result = binNum1 + binNum2;
        std::cout << "In binary form: " << binNum1 << " + " << binNum2 << " = " << result << std::endl;
        std::cout << "In base 10 form: " << binNum1.bin2Base10() << " + " << binNum2.bin2Base10() << " = "
            << result.bin2Base10() << std::endl;
        break;
    }
    case '*': {
        BinNum result = binNum1 * binNum2;
        std::cout << "In binary form: " << binNum1 << " * " << binNum2 << " = " << result << std::endl;
        std::cout << "In base 10 form: " << binNum1.bin2Base10() << " * " << binNum2.bin2Base10() << " = "
            << result.bin2Base10() << std::endl;
        break;
    }
    default:
        std::cout << "Invalid operation!" << std::endl;
        break;
    }
}
