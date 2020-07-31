#include<iostream>
#include<string>
using namespace std;
class dayType {
private:
	string day;
public:
	dayType() {
		day = '\0';
	}
	void setDay(string);
	void printDay();
	string retDay();
	string retNxtDay();
	string retPrevDay();
	//string retDesiredDay(int);
};
void dayType::setDay(string d) {
	day = d;
}
void dayType::printDay() {
	cout << "Today is " << day << endl;
}
string dayType::retDay() {
	return day;
}
string dayType::retNxtDay() {
	if (day == "sunday") {
		return "monday";
	}
	else if (day == "monday") {
		return "tuesday";
	}
	else if (day == "tuesday") {
		return "wednesday";
	}
	else if (day == "wednesday") {
		return "thursday";
	}
	else if (day == "thursday") {
		return "friday";
	}
	else if (day == "friday") {
		return "saturday";
	}
	else if (day == "saturday") {
		return "sunday";
	}
	else {
		return "Wrong input";
	}
}
string dayType::retPrevDay() {
	if (day == "sunday") {
		return "saturday";
	}
	else if (day == "monday") {
		return "sunday";
	}
	else if (day == "tuesday") {
		return "monday";
	}
	else if (day == "wednesday") {
		return "tuesday";
	}
	else if (day == "thursday") {
		return "wednesday";
	}
	else if (day == "friday") {
		return "thursday";
	}
	else if (day == "saturday") {
		return "friday";
	}
	else {
		return "Wrong input";
	}
}
int main() {
	dayType dt1;
	dt1.setDay("monday");
	cout << "Today is : " << dt1.retDay() << endl;
	cout << "Tomorrow is : " << dt1.retNxtDay() << endl;
	cout << "Yesterday was : " << dt1.retPrevDay() << endl;
	system("pause");
	return 0;
}