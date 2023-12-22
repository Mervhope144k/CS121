//Effects of constructors on objects

#include <iostream>
#include <iomanip>
using namespace std;

class inventory {
public:
	inventory();
	inventory(string);
	inventory(string, int, double);
	inventory(string, int, double, int);
	void printInventory() const;

	// Add additional functions

private:
	string name;
	int itemNum;
	double price;
	int unitsInstock;
};

inventory::inventory() { //default constructor
	name = " ";
	itemNum = -1;
	price = 0.0;
	unitsInstock = 0;
}

inventory::inventory(string n) {
	name = n;
	itemNum = -1;
	price = 0.0;
	unitsInstock = 0;
}

inventory::inventory(string n, int iNum, double cost) {
	name = n;
	itemNum = iNum;
	price = cost;
	unitsInstock = 0;
}

inventory::inventory(string n, int iNum, double cost, int inStock) {
	name = n;
	itemNum = iNum;
	price = cost;
	unitsInstock = inStock;
}

void inventory::printInventory() const {
	cout << "Name is " << name << endl;
	cout << "Number of items are " << itemNum << endl;
	cout << "Price is " << fixed << setprecision(2) << price << endl;
	cout << "Number of stock is " << unitsInstock << endl;
}


int main() {
	string Name;
	int Num;
	double Value;
	int Stock;

	//consider the following declarations:
	inventory item1;
	item1.printInventory();
	cout << endl;

	cout << "Enter Name" << endl;
	cin >> Name;
	cout << endl;

	inventory item2(Name);
	item2.printInventory();
	cout << endl;
	
	cout << "Enter Name, Num and Value" << endl;
	cin >> Name >> Num >> Value;
	cout << endl;

	inventory item3(Name, Num, Value);
	item3.printInventory();
	cout << endl;
	
	cout << "Enter Name, Num, Value and Stock" << endl;
	cin >> Name >> Num >> Value >> Stock;
	cout << endl;

	inventory item4(Name, Num, Value, Stock);
	item4.printInventory();
	cout << endl;
}

/*
Name is
Number of items are -1
Price is 0.00
Number of stock is 0

Enter Name
Dryer

Name is Dryer
Number of items are -1
Price is 0.00
Number of stock is 0

Enter Name, Num and Value
Washer 2345 278.95

Name is Washer
Number of items are 2345
Price is 278.95
Number of stock is 0

Enter Name, Num, Value and Stock
Toaster 8231 34.49 200

Name is Toaster
Number of items are 8231
Price is 34.49
Number of stock is 200


C:\Users\merve\Documents\CS121\ClassAndDataAbstraction\x64\Debug\ClassAndDataAbstraction.exe (process 25176) exited with code 0.
Press any key to close this window . . .
*/

