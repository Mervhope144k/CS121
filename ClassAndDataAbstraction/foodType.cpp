#include <iostream>
using namespace std;

class foodType
{
public:
	void set(string, int, double, int, double, double);
	void print() const;
	string getName() const;
	int getCalories() const;
	double getFat() const;
	int getSugar() const;
	double getCarbohydrate() const;
	double getPotassium() const;
	foodType();
	foodType(string, int, double, int, double, double);
private:
	string name;
	int calories;
	double fat;
	int sugar;
	double carbohydrate;
	double potassium;
};

i