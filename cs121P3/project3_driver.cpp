///////////////////////////////////////////////////////////////////////////////
//
// File Name         : project3_driver.cpp
//
// Purpose           : the main function of the program
//
// Programmer        : M.B Katumba
//
// Date Written      : 12/14/2023
//
// Date Last Revised : 12/16/2023
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "misc_ops.h"
#include "binNum.h"

int main() {
    char answer;
    bool check = true;

    greet();

    while (check) {
        int num1 = getUserBinaryInput();
        BinNum binNum1(num1);

        int num2 = getUserBinaryInput();
        BinNum binNum2(num2);

        displayMenu();
        char operation = getUserOperation();

        performOperation(binNum1, binNum2, operation);

        std::cout << "Would you like to try again? (Y or N)\n";
        std::cin >> answer;

        if (answer == 'n' || answer == 'N') {
            check = false;
        }
        else if (answer == 'y' || answer == 'Y') {
            check = true;
        }
    }

    std::cout << "Thank you for using our 4-bit binary calculator!" << std::endl;
    return 0;
}
