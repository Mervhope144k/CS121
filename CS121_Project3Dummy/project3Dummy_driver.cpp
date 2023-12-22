#include <iostream>
#include "misc_ops.h"

int main() {
    greet();
    char choice;

    do {
        displayMenu();
        char operation = getUserOperation();

        std::cout << "Enter the first 4-bit binary number:" << std::endl;
        BinNum firstNum = getUserBinaryInput();

        std::cout << "Enter the second 4-bit binary number:" << std::endl;
        BinNum secondNum = getUserBinaryInput();

        performOperation(firstNum, secondNum, operation);

        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
