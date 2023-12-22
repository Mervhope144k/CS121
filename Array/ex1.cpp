#include <iostream>
using namespace std;
int main()
{
	char s[10];
	cin >> s;
	int i;
	for (i = -1; s[++i] != '\0';)
		;
	cout << i << endl;
	return i;
	
}