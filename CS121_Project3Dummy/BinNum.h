#ifndef BINNUM_H_
#define BINNUM_H_
#include "bin_defs.h"
#include <iostream>
using namespace::std;

class BinNum
{
public:

    bool isValidBinary(char input[]);  //Function to check if entered value is a valid 4-bit binary number
    int bin2Base10();				//converts BinNum to integer equivalent
    char getBit(int i);			//returns bit at postion i


    BinNum();					//default constructor; creates binNum 0000
    BinNum(int num);			//creates binNum equal to 4 bin digits of num
    BinNum(const BinNum& initBinNum);  //copy constructor


    BinNum& operator = (const BinNum& initBinNum);
    BinNum operator + (BinNum& b);
    BinNum operator * (BinNum& b);




    friend ostream& operator << (ostream& s, BinNum& b);
    friend istream& operator >> (istream& s, BinNum& b);

private:
    char the_num[SIZE];			//THE binary num of SIZE bits - a char array
    void shiftBinNumBy(int shiftNum, BinNum& initBinNum);//shifts BinNum
};


#endif