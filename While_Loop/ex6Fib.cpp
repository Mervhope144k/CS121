//nth Fibonacci number
#include <iostream>
using namespace std;
int main() {
	int prev1, prev2, curr, count, nthFib;
	cout << "Enter the 1st and 2nd Fib num: ";
	cin >> prev1 >> prev2;
	cout << endl;
	cout << "The 1st and 2nd Fib num are " << prev1 << " and " << prev2 << endl;
	cout << "Enter the desire position of Fib num: ";
	cin >> nthFib;
	cout << endl;
	if (nthFib == 1) 
		curr == prev1;
	else if (nthFib == 2)
		curr = prev2;
	else {
		count = 3;
		while (count <= nthFib) {
			curr = prev2 + prev1;
			prev1 = prev2;
			prev2 = curr;
			count++;
		}//end while
	}//end else
	cout << "The Fib number at position " << nthFib << " is " << curr << endl;
	return 0;
}//end main