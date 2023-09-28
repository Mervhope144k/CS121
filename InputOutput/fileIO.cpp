// Skeleton form, a program that uses file I/O
#include <fstream>

// Add additional header files you need

using namespace std;

int main()
{
		// Declare file stream variables such as the following
	ifstream inData;
	ofstream outData;


		// open the files
	inData.open("prog.dat");  //open the input file
	outData.open("prog.out"); //open the output file
		
		//code for data manipulation

		//close files
	inData.close();
	outData.close();

	return 0;
}