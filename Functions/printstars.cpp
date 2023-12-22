//print a trianfle of starts
#include <iostream>
void printStars(int blanks, int starsInLine);
int main() {
	int noLines, counter, noBlanks;
	std::cout << "Enter number of star lines to be printed: ";
	std::cin >> noLines;
	while (noLines < 0 || noLines > 20) {
		std::cout << "Enter the number of star lines to be printed: ";
		std::cin >> noLines;
	}
	std::cout << std::endl << std::endl;
	noBlanks = 30;
	for (counter = 1; counter <= noLines; counter++) {
		printStars(noBlanks, counter);
		noBlanks--;
	}
}
void printStars(int blanks, int starsInLine) {
	int count;
	for (count = 1; count <= blanks; count++)
		std::cout << ' ';
	for (count = 1; count <= starsInLine; count++)
		std::cout << " *";
	std::cout << std::endl;
}
