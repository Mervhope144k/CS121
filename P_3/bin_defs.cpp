
///////////////////////////////////////////////////////////////////////////////
//
// File Name         : bin_defs.cpp
//
// This file contains the implementation of the addBits function
//
// Programmer        : B.J. Streller AND M.B. Katumba
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


char carry_bit = bit_0;		//initialize extern variable here

	
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
    char sum = bit_0; // Initialize sum to a default value
	
    if (bit1 == bit_0 && bit2 == bit_0) {
        sum = carry_bit;
        carry_bit = bit_0;
    }
    else if ((bit1 == bit_0 && bit2 == bit_1) || (bit1 == bit_1 && bit2 == bit_0)) {
        if (carry_bit == bit_0) {
            sum = bit_1;
        }
        else {
            sum = bit_0;
            carry_bit = bit_1;
        }
    }
    else if (bit1 == bit_1 && bit2 == bit_1) {
        sum = carry_bit;
        carry_bit = bit_1;
    }   
    return sum;
}
