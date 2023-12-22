#include "banking.h"

///////////
//
//Function name: getFileName
//
//Purpose: to prompt for the fully qualified name of a file
//			i.e. including the path
//
//Inout parameters: none
//
//Output parameters: none
//
//Return value: a string containinng the fully qualified name of file
////////////
string getFileName() {
	string fName;
	cout << "Please enter the fully qualified name of the "
		<< "inout text file (i.e. including the path):" << endl;
	getline(cin, fName);
	cout << endl;
	
	return fName;
}

/////////////
//Function name: openFile
//
//Purpose: open a file for input and output and check if it was successfully opened
//
//Input parameters: a string holding the name of the file and the file handle
//
//Output parameters: none
//
//Return value: none
//
/////////////
void openFile(string nameOf, fstream& inOut) {
	inOut.open(nameOf.c_str(), ios::in | ios::out | ios::app);
    if (!inOut) {
        cerr << "Cannot open file: " << nameOf << endl;
        exit(0);
    }
    else
        cout << "Horay!" << endl;
}