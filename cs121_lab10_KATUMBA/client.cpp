#include "binarySearch.h"

int main() {
	const int ValuesSIZE = 100;
	const int KeysSIZE = 10;
	int ValuesArray[ValuesSIZE];
	int KeysArray[KeysSIZE]{};
	int KeysIndex = 0;
	int ValuesIndex = 0;
	int key_int;
	int values_int;

	fstream InOutFile;
	string ValuesFile, SortedFile, KeysFile;
	
	cout << "Enter KeysFile: " << endl;
	KeysFile = getFileName();
	openFile(KeysFile, InOutFile);
	while (!InOutFile.eof() && KeysIndex < KeysSIZE) {
		InOutFile >> key_int;
		KeysArray[KeysIndex] = key_int;
		KeysIndex++;
	}
	InOutFile.close();

	cout << "Enter ValuesFile: " << endl;
	ValuesFile = getFileName();
	openFile(ValuesFile, InOutFile);
	while (!InOutFile.eof() && ValuesIndex < ValuesSIZE) {
		InOutFile >> values_int;
		ValuesArray[ValuesIndex] = values_int;
		ValuesIndex++;
	}

	cout << "Sorting of Values in progress..." << endl;
	BubbleSort(ValuesArray, ValuesSIZE);
	InOutFile.close();

	cout << "Enter file to store the sorted values: " << endl;
	SortedFile = getFileName();
	openFile(SortedFile, InOutFile);
	for (int i = 0; i < ValuesSIZE; i++)
		InOutFile << ValuesArray[i] << endl;
	InOutFile.close();

	for (int j = 0; j < KeysSIZE; j++) {
		int FoundIndex = BinarySearch(ValuesArray, ValuesSIZE, KeysArray[j]);
		if (FoundIndex != -1) {
			cout << "key value " << KeysArray[j] << " was located at index " 
				<< FoundIndex << " in the sorted array. " << endl;
		}
		else
			cout << "key value " << KeysArray[j] 
			<< " was not located in the sorted array. " << endl;
	}
	cout << "Showing output. Press enter to exit. \n";
	cin.ignore();
	char ch = getchar();
	return 0;
}

/*
Enter KeysFile:
Please enter the fully qualified name of the input text file (i.e. including the path):
C:\Users\merve\OneDrive - Erie Community College\C121\cs121_Lab10\keys.txt

Enter ValuesFile:
Please enter the fully qualified name of the input text file (i.e. including the path):
C:\Users\merve\OneDrive - Erie Community College\C121\cs121_Lab10\values.txt

Sorting of Values in progress...
Enter file to store the sorted values:
Please enter the fully qualified name of the input text file (i.e. including the path):
C:\Users\merve\OneDrive - Erie Community College\C121\cs121_Lab10\sortedValues.txt

key value 87 was located at index 83 in the sorted array.
key value 22 was located at index 20 in the sorted array.
key value 62 was not located in the sorted array.
key value 94 was located at index 93 in the sorted array.
key value 27 was not located in the sorted array.
key value 79 was located at index 76 in the sorted array.
key value 99 was not located in the sorted array.
key value 92 was located at index 90 in the sorted array.
key value 98 was located at index 98 in the sorted array.
key value 4 was located at index 3 in the sorted array.
Showing output. Press enter to exit.
*/