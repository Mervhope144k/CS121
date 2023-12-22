///////////////////////////////////////////////////////////////////////////////
//
// File Name         : misc_ops.h
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

#ifndef MISC_OPS_H_
#define MISC_OPS_H_

#include <iostream>
#include "binNum.h"

void greet();
void displayMenu();
char getUserOperation();
BinNum getUserBinaryInput();
void performOperation(BinNum& binNum1, BinNum& binNum2, char operation);

#endif#pragma once
