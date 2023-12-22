#include <iostream>
using namespace std;

class clockType
{
public:
	void setTime(int, int, int);
	void getTime(int&, int&, int&) const;
	void printTime() const;
	void incrementSeconds();
	void incrementMinutes();
	void incrementHours();
	bool equalTime(const clockType&) const;
	clockType(int = 0, int = 0, int = 0); //constructors with default parameters

private:
	int hr;
	int min;
	int sec;
};

void clockType::setTime(int hours, int minutes, int seconds) {
	if (0 <= hours && hours < 24)
		hr = hours;
	else
		hr = 0;
	if (0 <= minutes && minutes < 60)
		min = minutes;
	else
		min = 0;
	if (0 <= seconds && seconds < 60)
		sec = seconds;
	else
		sec = 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds) const {
	hours = hr;
	minutes = min;
	seconds = sec;
}

void clockType::printTime() const {
	if (hr < 10)
		cout << "0";
	cout << hr << ":";

	if (min < 10)
		cout << "0";
	cout << min << ":";
	if (sec < 10)
		cout << "0";
	cout << sec;
}

void clockType::incrementHours() {
	hr++;
	if (hr > 23)
		hr = 0;
}

void clockType::incrementMinutes() {
	min++;
	if (min > 59)
	{
		min = 0;
		incrementHours();
	}
}

void clockType::incrementSeconds() {
	sec++;
	if (sec > 59)
	{
		sec = 0;
		incrementMinutes();
	}
}

bool clockType::equalTime(const clockType& otherClock) const {
	return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

clockType::clockType(int hours, int minutes, int seconds)
{
	setTime(hours, minutes, seconds);
}

int main() {
	clockType clock1;
	clockType clock2(5);
	clockType clock3(12, 30);
	clockType clock4(7, 34, 18);

	cout << "clock1 " << endl;
	clock1.printTime();  //print clock1
	cout << endl;

	cout << "clock2" << endl;
	clock2.printTime(); //print clock2
	cout << endl;

	cout << "clock3" << endl;
	clock3.printTime(); // print clock3
	cout << endl;

	cout << "clock4" << endl; 
	clock4.printTime(); //print clock4
	cout << endl;
}//end main