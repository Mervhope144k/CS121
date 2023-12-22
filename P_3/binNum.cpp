
///////////////////////////////////////////////////////////////////////////////
//
// File Name         : binNum.cpp
//
// This file is the implementation of the binNum class
//
// Programmer        : B.J. Streller AND Merveilles Katumba Biende
//
// Date Written      : in the past
//
// Date Last Revised : 12/16/2023
//
///////////////////////////////////////////////////////////////////////////////


#include "binNum.h"
#include  <iostream>
#include  <cmath>
#include <cstring>
#include "bin_defs.h"
using namespace std;



///////////////////////////////////////////////////////////////////////////////
//
// Function name: BinNum()
//
// Purpose: consructor for BinNum class. Initializes bin num of SIZE bits to 0
//
//
// Input parameters: none
//					 
//
// Output parameters: none
//
// Return Value: a BinNum object initialized to 0
//
///////////////////////////////////////////////////////////////////////////////

BinNum::BinNum(){
    for (int i = 0; i < SIZE; ++i)
        the_num[i] = bit_0; // Initialize with all zeros  
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: BinNum( int num ) 
//
// Purpose: consructor for BinNum class. Initializes bin num of SIZE bits to 
//			input num	
//
// Input parameters: an int, treated as a bin num ( i.e only 0's and 1's),
//					 of length SIZE
//					 
// Output parameters: none
//
// Return Value: a BinNum object initialized to the value of input num
//
///////////////////////////////////////////////////////////////////////////////

BinNum::BinNum( int num ) : BinNum(){
    for (int i = SIZE - 1; i >= 0; --i) {
        the_num[i] = (num % 2) + bit_0; // Converting integer to binary
        num /= 2;
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: BinNum( const BinNum &initBinNum )
//
// Purpose: copy consructor for BinNum class. Creates a BinNum object which 
//			is a copy of the inputted BinNum objecdt
//
// Input parameters: a BinNum object of which copy of will be made
//					 
// Output parameters: none
//
// Return Value: a new BinNum object which is a copy of the input arg
//
///////////////////////////////////////////////////////////////////////////////

BinNum::BinNum( const BinNum &initBinNum ): BinNum()
{
    // cout << " calling copy constructor \n";
    for (int i = 0; i < SIZE; i++)
        ((*this).the_num[i]) = initBinNum.the_num[i];
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: operator =
//
// Purpose: overloaded assignment operator for BinNum class.
//
// Input parameters: a BinNum object which will be assigned to the left side
//			         =; i.e. this
//					 
// Output parameters: none
//
// Return Value: *this, the left hand side, which now has the "value" of 
//				 the input
//
///////////////////////////////////////////////////////////////////////////////

BinNum&  BinNum::operator = ( const BinNum &initBinNum )
{
    if (this == &initBinNum)
        return *this;   //avoid self assignment

    if (this != &initBinNum) {
        for (int i = 0; i < SIZE; ++i)
            the_num[i] = initBinNum.the_num[i]; // Copy assignment
    }//loop to assign array elements

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: operator +
//
// Purpose: overloaded + operator for BinNum class.
//
// Input parameters: a BinNum object, b1, which is the second addend in +
//			        					 
// Output parameters: none
//
// Return Value: a BinNum object which is the sum of the calling object, 
//				 this, and b1
//
///////////////////////////////////////////////////////////////////////////////

BinNum BinNum::operator+ ( BinNum &b1 )
{
    BinNum temp;

    int carry = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        temp.the_num[i] = addBits(the_num[i], b1.the_num[i]);
    }
    return temp;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: operator *
//
// Purpose: overloaded * operator for BinNum class.
//
// Input parameters: a BinNum object, b1, which is the multiplier in *
//			        					 
// Output parameters: none
//
// Return Value: a BinNum object which is the product of the calling object, 
//				  the multiplicand (represented by this), and b1
//
///////////////////////////////////////////////////////////////////////////////

BinNum BinNum::operator* ( BinNum &b1 )
{
    BinNum product;				//resulting product of this and b1
    BinNum partialProd[SIZE];	//an array storing all the partial products
								//of the multiplicand by a single bit

    for (int i = SIZE - 1; i >= 0; --i) {
        if (b1.the_num[i] == bit_1) {
            partialProd[i] = *this;
            partialProd[i].shiftBinNumBy(SIZE - 1 - i, partialProd[i]);
        }
        else {
            partialProd[i] = BinNum(); // Initialize to 0
        }
    }

    product = partialProd[0];
    for (int i = 1; i < SIZE; ++i) {
        product = product + partialProd[i];
    }
  

    return product;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: bin2Base10( )
//
// Purpose: converts BinNum object of SIZE bits to integer equivalent
//
// Input parameters: none
//			        					 
// Output parameters: none
//
// Return Value: the integer equivalent of the calling object, 
//
///////////////////////////////////////////////////////////////////////////////

int BinNum::bin2Base10( )
{
    int num = 0;
    for ( int i = 0; i < SIZE; i++)
        {
            if(  getBit(i) == bit_1)
                num += (int)(pow( 2.0, SIZE - 1 - i ));
        }
    return num;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function name: getBit( int i)
//
// Purpose: gets the bit at position i of the BinNum object
//
// Input parameters: an int, i, a position in the bin num
//			        					 
// Output parameters: none
//
// Return Value: a char, the bit ( '0' or '1' ) of the BinNum object
//
///////////////////////////////////////////////////////////////////////////////

char BinNum::getBit( int i)
{
    return  (  this -> the_num[i] );
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: <<
//
// Purpose: overloaded insertion operator for a BinNum object; allows for easy
//			outputting
//
// Input parameters: a BinNum object, and an output stream
//			        					 
// Output parameters: none
//
// Return Value: an output stream object
//
///////////////////////////////////////////////////////////////////////////////

ostream &operator<<( ostream &s, BinNum &b )
{
    for(int i = 0; i < SIZE ; ++i ){
        s << b.the_num[i];
    }
    return s;
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: >>
//
// Purpose: overloaded extraction operator for a BinNum object; allows for easy
//			inputting
//
// Input parameters: a BinNum object, and an input stream
//			        					 
// Output parameters: none
//
// Return Value: an input stream object
//
///////////////////////////////////////////////////////////////////////////////

istream &operator>>( istream &s, BinNum &b )
{
    for (int i = 0; i < SIZE; ++i) {
        s >> b.the_num[i];
    }
    return s;
}


///////////////////////////////////////////////////////////////////////////////
//
// Function name: shiftBinNumBy
//
// Purpose: a helper function used by *. Shifts a BinNum object shiftNum 
//			of places left
//	
// Input parameters: an int shiftNum, representing the number of places to 
//					 shift left the input initBinNum object. shiftNum must
//					 be <= SIZE. And the calling object, this.
//			        					 
// Output parameters: this which will be the shifted BinNum object
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////

void  BinNum::shiftBinNumBy( int shiftNum, BinNum& initBinNum ){
    if (shiftNum > SIZE) {
        cout << "Error: shiftNum exceeds SIZE." << endl;
        return;
    }

    // Shifting the binary number to the left by shiftNum places
    for (int i = SIZE - shiftNum -1 ; i >= 0; --i) {
        initBinNum.the_num[i + shiftNum] = initBinNum.the_num[i];
    }

    for (int i = 0; i < shiftNum; ++i) {
        initBinNum.the_num[i] = bit_0; // Filling with zeros for the shifted positions
    }
}

///////////////////////////////////////////////////////////////////////////////
//
// Function name: isBinary
//
// Purpose: Function to check if entered value is a valid 4-bit binary number
//
// Input parameters: char input[] : a character array
//			        					 
// Output parameters: boolean value
//
// Return Value: bool
//
///////////////////////////////////////////////////////////////////////////////

bool BinNum::isBinary(char input[]) {
    if (std::strlen(input) == 4 && std::strspn(input, "01") == 4) {
        strcpy_s(the_num, sizeof(the_num), input);
        return true;
    }
    return false;
}




