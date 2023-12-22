#include <iostream>
using namespace std;
int main() {
	int counter, nthFibonacci, current, previous1, previous2;
	current = 0;
	cin >> previous1 >> previous2;
	cout << endl;
	cin >> nthFibonacci;
	for (counter = 3; counter <= nthFibonacci; counter++) {
		current = previous2 + previous1;
		previous1 = previous2;
		previous2 = current;
	}
	cout << current << endl;
	return 0;
}