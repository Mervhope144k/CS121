
///////////////////////////////////////////////////////////////////////////////
//
// File Name         : bin_defs.cpp
//
// This file contains the implementation of the addBits function
//
// Programmer        : B.J. Streller and Moe Myint Maung
//
// Date Written      : in the past
//
// Date Last Revised : 2022 November
//
///////////////////////////////////////////////////////////////////////////////


#include "bin_defs.h"
#include  <cmath>
#include <iostream>
using namespace std;


char carry_bit = '0';		//initialize extern variable here

	
///////////////////////////////////////////////////////////////////////////////
//
// Function name: addBits
//
// Purpose: performs the binary "addtion" of 2 chars ( '0' and '1' )
//
// Input parameters: 2 chars repesenting the bits 0 an 1
//					 
// Output parameters: none
//
// Return Value: the sum of the 2 inputted bits, as a char
//
///////////////////////////////////////////////////////////////////////////////

char addBits( char bit1, char bit2 )
{
    char sum = '0';

	//you add code to add bits
    if (bit1 == '0' && bit2 == '0') {
        sum = carry_bit;
        carry_bit = '0';
    }
    else if ((bit1 == '1' && bit2 == '0') || (bit1 == '0' && bit2 == '1')) {
        if (carry_bit == '0') {
            sum = '1';
        }
        else {
            sum = '0';
            carry_bit = '1';
        }
    }
    else { // Both bits are '1'
        sum = carry_bit;
        carry_bit = '1';
    }

    return sum;

}



///////////////////////////////////////////////////////////////////////////////