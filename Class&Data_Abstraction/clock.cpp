//The program listing of the program that defines and uses the class clockType

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

private:
	int hr;
	int min;
	int sec;
};

int main() {
	clockType myClock;
	clockType yourClock;
	int hours;
	int minutes;
	int seconds;

	//set the time of myClock
	myClock.setTime(5, 4, 30);

	cout << "myClock: ";
	myClock.printTime(); //print the time of myClock
	cout << endl;

	cout << "yourClock: ";
	yourClock.printTime(); //print the time of yourClock
	cout << endl;

	//ser the time of yourClock
	yourClock.setTime(5, 45, 16);

	cout << "After setting, yourClock: ";
	yourClock.printTime(); //print teh time of yourClock
	cout << endl;

	//Compare myClock and yourClock
	if (myClock.equalTime(yourClock))
		cout << "Both times are eual." << endl;
	else
		cout << "The two times are equal." << endl;
	cout << "Enter the hours, minutes, and seconds: ";
	cin >> hours >> minutes >> seconds;
	cout << endl;

	//Set the time of myClock using the value of the variables hours, minutes and seconds
	myClock.setTime(hours, minutes, seconds);

	cout << "New myClock: ";
	myClock.printTime(); //print the time of myClock
	cout << endl;

	//Increment teh time of myClock by one second
	myClock.incrementSeconds();

	cout << "After incrementing myClock by one sencond, myClock: ";
	myClock.printTime(); //print the time of myClock
	cout << endl;

	//Retrieve the hours, minutes, and seconds of the object myClock
	myClock.getTime(hours, minutes, seconds);

	//Output the value of hours, minutes, and seconds of the object myClock
	cout << "hours = " << hours << ", minutes = " << minutes << ", seconds = " << seconds << endl;
	return 0;
}//end main

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