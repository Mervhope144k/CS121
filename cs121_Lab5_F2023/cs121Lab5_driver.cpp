

#include <fstream>										//for ifstream                                      
#include <iostream>										//cin, cout,cerr                                  
#include <string>										//for string data type                                     
#include <stdlib.h>										//for exit
using namespace std;



//create a "macro" defining what are white space chars
//a macro is a piece of code that is replaced by the value of the macro in
//the program. Whenever a compiler encounters the macro name, it replaces
//it with the definition of the macro.
//in this case, you can treat the experssion white_space as a "substitution"
//for the characters below.

#define white_space ( whsp == ' ' || whsp == '\n'  ||  whsp == '\t'  \
                    || whsp == ',' /*YOU WILL NEED TO ADD OTHER CHARS HERE*/ )






// function prototypes

string getInputFileName();						//prompt for complete file name
void openFile(string nameOf, ifstream &in);		//open file for reading
int numWordsInFile( ifstream &in );				//count words in a file





///////////////////////////////////////////////////////////////////////////////


int main ()
{

    int nWords;								//number of words in text file
    ifstream inFile;						//handle for input file
    string fileName;						//complete name including path

    fileName = getInputFileName();			//prompt and get full file name
    openFile(fileName, inFile);				//open file

    nWords = numWordsInFile( inFile );		//determine words in file


    cout << "The number of words in the file: " << fileName
         << " is = " << nWords << endl << endl;


    inFile.close(); // close the input file

    return 0;
}



///////////////////////////////////////////////////////////////////////////////
//
// Function name: getInputFileName
//
// Purpose: to prompt for the fully qualified name of a file
//              i.e. including the path of the file
//
// Input parameters: none
//
// Output parameters: none
//
// Return Value: a string containing the fully qualified name
//               of a file
//
///////////////////////////////////////////////////////////////////////////////

string getInputFileName()
{
    string fName; // fully qualified name of the file

    cout << "Please enter the fully qualified name of the " << endl
         << "input text file (i.e. including the path): ";
    cin >> fName;
	
    cout << endl; // skip a line

    return fName;
}




///////////////////////////////////////////////////////////////////////////////
//
// Function name: openFile
//
// Purpose: open a file and check if it was successfilly opened

//
// Input parameters: a string holding the name of the file
//					 and the file handle
//
// Output parameters: none
//
// Return Value: none
//
///////////////////////////////////////////////////////////////////////////////

void openFile(string nameOf, ifstream &in)
{
    in.open(nameOf.c_str(), ios::in );		//convert nameOf to c-string; try to open
    if( !in )						//file and test for unsuccessful opening
        {
            cerr << "Cannot open file: " << nameOf << endl << endl;
            exit (0);
        }

}



//////////////////////////////// numwordsInFile ///////////////////////////////
//
// Function name: numWordsInFile
//
// Purpose: counts the number of words in a text file
//
//
// Input parameters: in - a file handle pointing (pass by reference)
//                        to the input file
//
// Output parameters: none
//
//
// Return Value: the number of words in the text file
//
///////////////////////////////////////////////////////////////////////////////




int numWordsInFile( ifstream &in )
{

    int numWords = 0;					//number of words

    char whsp;							//stores char from file read
    char word = 'O';					//keep track if In or Out of word
    //O is for "out" of the word
    //use I for "in" the word

//use a while loop to read/get file content char by char.
//inside the loop see if you have white_space
//if you have white_space, set word = 'O' ( you are OUT of a word )
//else set word = 'I' ( you are IN a word )
//increment numWords when appropriate



    return numWords;

}



///////////////////////////////////////////////////////////////////////////////



