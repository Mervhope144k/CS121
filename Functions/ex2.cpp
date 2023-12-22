#include <iostream>
double larger (double x, double y);
double compareThree(double a, double b, double c);
int main() {
	double one, two, three = 0.0;
	std::cout << "Enter one, two and three: ";
	std::cin >> one >> two >> three;
	std::cout << "The larger of " << one << " and " << two << " is " << larger(one, two) << std::endl;
	std::cout <<"The largest of " << one << "; " << two << " and " << three << " is " << compareThree(one, two, three);
	std::cout << std::endl;
}
double larger(double x, double y) {
	double max = 0;
	if (x > y)
		max = x;
	else if (x == y)
		std::cout << "numbers are equal";
	else
		max = y;
	return max;
}
double compareThree(double a, double b, double c) {
	return larger(a, larger(b, c));
}
