/*
* FileName: lab6_driver.cpp
* Description: This program will search a file fora specified id number.
* If the the id number is found, the person's name is printed to the terminal.
* If the id number is not found,
* No such person with that id is printed to cout stream.
* Input file: roster.txt
* Output file: roster.txt
* Programmer: M.B. Katumba
* Date written: 10/28/23
* Date Last Revised: 10/28/23
*/

#include <fstream>			//for ifstream                                      
#include <iostream>			//cin, cout,cerr                                  
#include <string>			//for string data type                                     
#include <stdlib.h>			//for exit
using namespace std;

string getInputFileName();			//prompt for complete file name
void openFile(string nameOf, fstream& inOut);	//open file for reading
int searchID(int array[], const int SIZE, int key);
//void addToFile(fstream& file, const string& id, const string& name);




///////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////

string getInputFileName()
{
	string fName; // fully qualified name of the file

	cout << "Please enter the fully qualified name of the " << endl
		<< "input text file (i.e. including the path): ";
	cin >> fName;

	cout << endl; // skip a line

	return fName;
}


/////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////

void openFile(string nameOf, fstream& inOut)
{
	//convert nameOf to c-string; try to open
	inOut.open(nameOf.c_str(), ios::in | ios::out | ios::app);
	//file and test for unsuccessful opening
	if (!inOut)
	{
		cerr << "Cannot open file: " << nameOf << endl;
		exit(0);
	}
}


int searchID(int array[], const int SIZE, int key)
{
	int i;
	for (i = 0; i < SIZE; i++)
	{
		if (key == array[i])
			return i;
	}
	return -1;
}

//void addToFile(fstream& file, const string& id, const string& name)
//{
	
//}

int main()
{
	fstream InOutFile;		//handle for input file
	string fileName;		//complete name including path

	fileName = getInputFileName();	//prompt and get full file name
	openFile(fileName, InOutFile);	//open file

	const int ArraySize = 20;
	int id_Number[ArraySize]{};
	int count = 0;
	string name[ArraySize];
	int IdToFind{};
	int IdFound;

	while (!InOutFile.eof())
	{
		InOutFile >> id_Number[count];
		InOutFile >> name[count];
		count++;
	}

	InOutFile.clear();		//clear file stream
	InOutFile.seekg(0L, ios::beg); //reset file stream
	bool errorcheck = true;
	while (errorcheck == true)
	{
		cout << "Enter an ID number to search for (or 'q' to quit): ";
		cin >> IdToFind;

		if (IdToFind < 1)
		{
			cout << "You have entered a very short ID number" << endl;
			continue;
		}
		else
			errorcheck = false;

	}
	IdFound = searchID(id_Number, ArraySize, IdToFind);
	if (IdFound < -1)
	{
		string NewName;
		cout << "No such ID found."
			<< "A new ID will be recorded with a name"
			<< endl;
		cout << "Enter a new name";
		cin >> NewName;
		InOutFile << IdToFind << '\t' << NewName;
	}
	else
	{
		if (IdFound > -1)
		{
			cout << "Welcome " << name[IdFound]
				<< ", Your ID is " << id_Number[IdFound] << endl;
		}

	}
	InOutFile.close();

	cout << "Press Enter key to exit. \n";
	cin.ignore();
	char ch = getchar();
}


//}
//{

	//while (true)
	//{
		//string idToFind, foundName;
			//cout << "Enter an ID number to search for (or 'q' to quit): ";
			//cin >> idToFind;

			//if (idToFind == "q" || idToFind == "Q")
			//{
			//	break;
			//}

			//file.clear();
			//file.seekg(0L, ios::beg);

			//if (searchID(file, idToFind, foundName))
		//	{
			//	cout << "Person's Name: " << foundName << endl;
//
		//	}
	//		else
	//		{
	//			cout << "No such person with ID" << idToFind << endl;
		//		char option;
		//		cout << "Do you want to add this person's info (Y/N)? ";
		//		cin >> option;

		//		if (option == 'Y' || option == 'y')
				//{
		//			string name;
			//		cout << "Enter the person's name: ";
		///			cin.ignore();
		//			getline(cin, name);
		//
		//			addToFile(file, idToFind, name);
			//		cout << "Person's information added to the file." << endl;
			//	}
		//	}
		//	file.clear();
		//	file.seekg(0L, ios::beg);
	//}
	//file.close();
	//return 0;

//}

