//Fibonacci
#include <iostream>
int nthFib(int num1, int num2, int position);
int main() {
	int Fib1, Fib2, nthFibonacci = 0;
	std::cout << "Enter first two numbers: ";
	std::cin >> Fib1 >> Fib2;
	std::cout << std::endl;
	std::cout << "The first two Fib Numbers are " << Fib1 << " and " << Fib2 << std::endl;
	std::cout << "Enter the position you want: ";
	std::cin >> nthFibonacci;
	std::cout << std::endl;
	std::cout << "The Fib number at position " << nthFibonacci << " is " << nthFib(Fib1, Fib2, nthFibonacci) << std::endl;
	return 0;
}
int nthFib(int num1, int num2, int nthFibNum) {
	int curr = 0;
	int count = 0;
	if (nthFibNum == 1)
		curr = num1;
	else if (nthFibNum == 2)
		curr = num2;
	else{
		count = 3;
		while (count <= nthFibNum) {
			curr = num2 + num1;
			num1 = num2;
			num2 = curr;
			count++;
		}
	}
	return curr;
}
