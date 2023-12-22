//Pass by value or Value parameter
#include <iostream>
void funcValueParameter(int num);
int main() {
	int number = 6;
	std::cout << "Before calling funtion, parameter is " << number << std::endl;
	funcValueParameter(number);
	std::cout << "After calling function, parameter is " << number << std::endl;
	return 0;
}
void funcValueParameter(int num) {
	std::cout << "Before function execution, parameter is " << num << std::endl;
	num = 15;
	std::cout << "After function execution, parameter is " << num << std::endl;
}