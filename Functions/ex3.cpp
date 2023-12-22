//Program: roll dice
#include <iostream>
#include <ctime>
#include <cstdlib>

int rollDice(int x);
int main() {
	int num = 0;
	std::cout << "Enter the number you want: ";
	std::cin >> num;
	std::cout << " rolls to " << num << ": " << rollDice(num);
}
int rollDice(int num) {
	int die1, die2, sum, rollCount = 0;
	srand(time(0));
	do {
		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		sum = die1 + die2;
		rollCount++;
	} while (sum != num);
	return rollCount;
}