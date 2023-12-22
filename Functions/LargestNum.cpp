//Largest Number
#include <iostream>
double larger(double x, double y);
int main() {
	double num, max;
	int count;
	std::cout << "Enter 10 numbers." << std::endl;
	std::cin >> num;
	max = num;
	for (count = 1; count < 10; count++) {
		std::cin >> num;
		max = larger(max, num);
	}
	std::cout << "The largest number is " << max << std::endl;
	return 0;
}
double larger(double x, double y) {
	if (x > y)
		return x;
	else if (x == y)
		return 0;
	else
		return y;
}