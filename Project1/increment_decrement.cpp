//Program to see the behavior of increment and decrement operator(Post and Pre)

#include <iostream>
using namespace std;

int main()
{
	int x, y;
	x = 5;
	cout << " x = " << x << endl;
	y = 2 + (x++);
	cout << " x = " << x << endl;
	cout << " y = " << y << endl;
	return 0;
}