//*******************************************************
//	Programmer: Merveilles Katumba Biende
//	Instructor: B.J. Streller
//	Course: CS 121
//	Date: 11/07/2023
//	Program Name: Bubble sorting algorithm
//	Program File: lab8_driver.cpp
//	Purpose: This program use the bubble sort algorithm
//           to sort an array of integers.
// Description: Prompt user for the fully qualified name of the file
//              The array to be sorted contains 500 integers.
//              The sorted array must be printed to a file,
//              user chooses name, with a single integer on each line
//              The last line of the output file must contain
//              the number of times integer values were swapped
//******************************************************

#include <iostream>         //for cin and cout streams
#include <fstream>          //for file manipulation
#include <utility>          //for built-in swap function

using namespace std;

///PROTOTYPES

//Bubble sort algorithm
void bubbleSort(int dataArray[], const int size, int& numOfSwaps);

//get file input path
string getFileName();

//*******************************************
//  Function Name: bubbleSort
//	Purpose: sort an array of interger.
//	Parameters: int dataArray[], const int size, int& numOfSwaps
//	Return Value: None
//	Global Variables Used: None
//*******************************************

void bubbleSort(int dataArray[], const int size, int& numOfSwaps)
{
	int i, j;
	bool swapped;
	numOfSwaps = 0;
	do
	{
		swapped = false;
		for (i = 0; i < size; i++)
		{
			for (j = size - 1; j > i; j--)
			{
				if (dataArray[j] < dataArray[j - 1])
				{
					swap(dataArray[j], dataArray[j - 1]);
					swapped = true;
					numOfSwaps++;
				}
			}
		}
	} while (swapped);
	
}

//***********************************************************
// Function name: getFileName
// Purpose: to prompt for the fully qualified name of a file
// i.e. including the path of the file
// Input parameters: none
// Output parameters: none
// Return Value: a string containing the fully qualified name
//               of a file
//***********************************************************

string getFileName()
{
	string fName;
	cout << "Please enter the fully qualified name of the " 
	<< "input text file (i.e. including the path):" << endl;
	cin >> fName;
	cout << endl;
	return fName;
}

//////MAIN///////
int main()
{
    const int arraySize = 500;
    int data[arraySize];
    int numSwaps;

    // Step 1: Prompt user for the input file name
    string inputFileName = getFileName();

    // Step 2: Open and read data from the input file
    ifstream inputFile(inputFileName);
    if (!inputFile)
    {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (!(inputFile >> data[i]))
        {
            cerr << "Error reading data from input file." << endl;
            return 1;
        }
    }

    inputFile.close();

    // Step 3: Sort the array and count swaps
    bubbleSort(data, arraySize, numSwaps);

    // Step 4: Prompt user for the output file name
    string outputFileName;
    cout << "Please enter the name of the output text file for sorted data:" << endl;
    cin >> outputFileName;

    // Step 5: Write sorted data to the output file
    ofstream outputFile(outputFileName);
    if (!outputFile)
    {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    for (int i = 0; i < arraySize; i++)
    {
        outputFile << data[i] << endl;
    }

    // Step 6: Append the number of swaps to the output file
    outputFile << "Number of swaps: " << numSwaps << endl;

    outputFile.close();

    cout << "Sorting complete. Sorted data and number of swaps saved to " << outputFileName << "." << endl;

    return 0;
}
//OUTPUT
/*
Please enter the fully qualified name of the input text file (i.e. including the path):
C:\Users\katumbm053\Desktop\nums.txt

Please enter the name of the output text file for sorted data:
C:\Users\katumbm053\Desktop\sortedNums.txt
Sorting complete. Sorted data and number of swaps saved to C:\Users\katumbm053\Desktop\sortedNums.txt.

C:\Users\katumbm053\OneDrive - Erie Community College\C121\Lab8\x64\Release\Lab8.exe (process 11216) exited with code 0.
Press any key to close this window . . .
*/