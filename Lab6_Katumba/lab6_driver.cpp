/*
* FileName: lab6_driver.cpp
* Description: This program will search a file fora specified id number.
* If the the id number is found, the person's 
* name is printed to the terminal.
* If the id number is not found,
* No such person with that id is printed to cout stream.
* Input file: roster.txt
* Output file: roster.txt
* Programmer: M.B. Katumba
* Date written: 10/28/23
* Date Last Revised: 10/28/23
*/

#include <fstream>                            // need for fstream
#include <iostream>                          // need for cin, cout
#include <string>                           // need for strings
#include <stdlib.h>                        // need for exit
#include <stdio.h>                        // need for getchar()


using namespace std;


//function prototypes

string getFileName();               // prompt for complete file name
void openFile(string nameOf, fstream& inOut);  // open file for reading
//int getId(fstream& inOut, int& id);            // prompt to enter an ID
int SearchId(fstream& inOut, int& id); // prompt to search file for ID

////////////////////////////////////////////////////////////
//
// Function name: getFileName
//
// Purpose: to prompt for the fully qualified name of a file
// i.e. including the path of the file
//
// Input parameters: none
//
// Output parameters: none
//
// Return Value: a string containing the fully qualified name
//               of a file
//
////////////////////////////////////////////////////////////

string getFileName()
{
    string fName;

    cout << "Please enter the fully qualified name of the " << endl
        << "input text file(i.e.including the path) : ";
    cin >> fName;

    cout << endl;   // skip a line

    return fName;
}

/////////////////////////////////////////////////////////
//
// Function name: openFile
//
// Purpose: open a file for input and output 
// and check if it was successfilly opened
// Input parameters: a string holding the name of the file
//					 and the file handle
//
// Output parameters: none
//
// Return Value: none
//
///////////////////////////////////////////////////

void openFile(string nameOf, fstream& inOut)
{
    inOut.open(nameOf.c_str(), ios::in | ios::out | ios::app);
    if (!inOut)
    {
        cerr << "Cannot open file: " << nameOf << endl << endl;
        exit(0);
    }
}

//////////////////////////////// SearchId ////////////////
//
// Function name: SearchId
//
// Purpose: searchs for ID (passed by reference) and name in the file
//
//
// Input parameters: file handle and the ID passed by reference 
//
// Output parameters: none
//
//
// Return Value: num if the id is found or -1 if not found
//
//////////////////////////////////////////

int SearchId(fstream& inOut, int& id)
{
    int number;
    string name;
    while (inOut >> number)
    {
        inOut >> name;
        if (id == number)
        {
            cout << "Person's name: " << name << endl;
            return number;
        }
    }
    return -1;
}

/////////////MAIN///////////////
int main()
{    
        fstream InOutFile;       // handle for file
        string fileName;         // complete name of file including path
        fileName = getFileName();   // prompt and get full file name
        openFile(fileName, InOutFile);  // open file
        int idNumber;
        int result;
        char q;
        string name;

        while (true)   // will loop indefinetly until user wishes to exit
        {
            cout << "Please enter an ID: ";
            cin >> idNumber;                 
            result = SearchId(InOutFile, idNumber); // searching ID in file
            InOutFile.clear();    // reset bits past eof()
            InOutFile.seekg(0l, ios::beg);   // return to beginning of file

            if (result > -1)  // prompt the user for an option
            {
                cout << "Do you want to continue or leave? " << endl;                   
                cout << "Press (y/Y) to continue OR (n/N)" 
                    << " to exit this program." << endl;
                cin >> q;
                cin.ignore();
                if (q == 'n' || q == 'N')
                {
                    InOutFile.close();    // close the input file
                    return 0;   // end program
                }
            }
            else
                if (result == -1)  // id is not found
                {
                    cout << "No such person's ID found." << endl;

                    cout << "Do you want to add this person's"
                        << " info (Y/N) ?";
                    cin >> q;
                    cin.ignore();

                    if (q == 'n' || q == 'N')
                    {
                        InOutFile.close();   // close the input file
                        return 0;            // end program
                    }

                    else
                    {
                        cout << "Enter the name of this person: ";
                        getline(cin, name);
                        InOutFile << idNumber << '\t' << name << endl;
                        cout << "The info of " << name << " with their ID: "
                            << idNumber << " has been added to "
                            << fileName << endl;
                        cout << "Do you want to continue or leave? " << endl;
                        cout << "Press (y/Y) to continue OR (n/N)"
                            << " to exit this program." << endl;
                        cin >> q;
                        cin.ignore();
                        if (q == 'n' || q == 'N')
                        {
                            InOutFile.close();    // close the input file
                            return 0;   // end program
                        }
                        InOutFile.clear();     // reset bits past eof()
                        InOutFile.seekg(0l, ios::beg);  // return to the beginning of file 
                    }
                }
        }
        InOutFile.clear();     // reset bits past eof()
        InOutFile.seekg(0l, ios::beg);  // return to the beginning of file           
        InOutFile.close();    // close the input file
        cout << "Press any key to continue" << endl;
        cin.ignore();
        char ch = getchar();
        return 0;   // end program
}
/*
Please enter the fully qualified name of the
input text file(i.e.including the path) : C:\Users\merve\Documents\CS121\CSlab6\roster.txt

Please enter an ID: 765
Person's name: merv
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
y
Please enter an ID: 123
Person's name: goofy
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
y
Please enter an ID: 444
Person's name: bugs
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
y
Please enter an ID: 323
Person's name: porky
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
y
Please enter an ID: 155
No such person's ID found.
Do you want to add this person's info (Y/N) ?y
Enter the name of this person: Moe
The info of Moe with their ID: 155 has been added to C:\Users\merve\Documents\CS121\CSlab6\roster.txt
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
y
Please enter an ID: 666
Person's name: WALT
Do you want to continue or leave?
Press (y/Y) to continue OR (n/N) to exit this program.
n

C:\Users\merve\Documents\CS121\CSlab6\x64\Release\CSlab6.exe (process 40064) exited with code 0.
Press any key to close this window . . .
*/