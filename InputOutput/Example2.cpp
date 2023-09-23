//Working of the >> extraction operator

#include <iostream>
using namespace std;
int main()
{
	int i = 0;
	while (i++ < 30)
	{
		if (i > 10 && i < 20)
			continue;
		else
			cout << "i is " << i << endl;
	}
	return 0;
}