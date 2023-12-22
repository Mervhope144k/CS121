#include "misc_ops.h"
#include <iostream>

void greet() {
    std::cout << "Welcome to the Binary Number Calculator!" << std::endl;
}

void displayMenu() {
    std::cout << "Select an operation:" << std::endl;
    std::cout << "1. Addition" << std::endl;
    std::cout << "2. Multiplication" << std::endl;
}

char getUserOperation() {
    char operation;
    std::cout << "Enter operation (1 for Addition, 2 for Multiplication): ";
    std::cin >> operation;
    return operation;
}

BinNum getUserBinaryInput() {
    char input[SIZE];
    BinNum binNumber;

    do {
        std::cout << "Enter a valid 4-bit binary number: ";
        std::cin >> input;
    } while (!binNumber.isValidBinary(input));

    return binNumber;
}

void performOperation(BinNum& binNum1, BinNum& binNum2, char operation) {
    if (operation == '1') {
        BinNum sum = binNum1 + binNum2;
        std::cout << "In binary form: " << binNum1 << " + " << binNum2 << " = " << sum << std::endl;
        std::cout << "In base 10 form: " << binNum1.bin2Base10() << " + " << binNum2.bin2Base10() << " = " << (binNum1 + binNum2).bin2Base10() << std::endl;
    }
    else if (operation == '2') {
        BinNum product = binNum1 * binNum2;
        std::cout << "In binary form: " << binNum1 << " * " << binNum2 << " = " << product << std::endl;
        std::cout << "In base 10 form: " << binNum1.bin2Base10() << " * " << binNum2.bin2Base10() << " = " << (binNum1 * binNum2).bin2Base10() << std::endl;
    }
    else {
        std::cout << "Invalid operation selected!" << std::endl;
    }
}
