#ifndef MISC_OPS_H_
#define MISC_OPS_H_

#include "BinNum.h"

void greet();
void displayMenu();
char getUserOperation();
BinNum getUserBinaryInput();
void performOperation(BinNum& binNum1, BinNum& binNum2, char operation);

#endif

