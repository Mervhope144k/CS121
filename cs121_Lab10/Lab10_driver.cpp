/*******************************
* Programmer: Merveilles Katumba
* Professor: BJ. Streller
* File names: Lab10_driver.cpp, binarySearch.h, client.cpp
* course: CS 121
* Description: Use sorting algorithm to sort interger values from a file,
*				Use searching algorithm, specifically binary search 
				to find keys from a different file.
*				print in the console keys found and position and those not found.
* Date: 11/23/23
*********************************/


#include "binarySearch.h"

///////////
//
//Function name: getInputFileName
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
	<< "input text file (i.e. including the path): " << endl;
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
		cerr << "Cannot open file: " << nameOf << endl << endl;
		exit(0);
	}
}

/////////////
//Function name: BubbleSort
//
//Purpose: sort an array of intergers
//
//Input parameters: an array of integers and the array size
//
//Output parameters: none
//
//Return value: none
//
/////////////

void BubbleSort(int array[], const int SIZE) {
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = SIZE - 1; j > i; j--) {
			if (array[j] < array[j - 1])
				swap(array[j], array[j - 1]);
		}
	}
}

/////////////
//Function name: BinarySearch
//
//Purpose: search through an array of intergers for an interger key
//
//Input parameters: an array of integers, the array size and the keyto be searched
//
//Output parameters: none
//
//Return value: an interger index
//
/////////////

int BinarySearch(int array[], const int SIZE, int key) {
	int L = 0, R = SIZE - 1, M;
	while (L <= R) {
		M = (L + R) / 2;
		if (key == array[M])
			return M;
		else if (key < array[M])
			R = M - 1;
		else
			L = M + 1;
	}//end while loop
	return -1; //not found
}//end function