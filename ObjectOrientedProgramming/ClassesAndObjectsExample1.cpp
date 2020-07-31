#include<iostream>
using namespace std;
class ClassRoom {
private: //private data members
	int id, NumberOfFans, NumberOfChairs, NumberOfTables;
public: //public data members
	//constructor
	ClassRoom() {
		id = 0;
		NumberOfFans = 0;
		NumberOfChairs = 0;
		NumberOfTables = 0;
	}
	//setters
	void setId(int i) {
		id = i;
	}
	void setFans(int f) {
		NumberOfFans = f;
	}
	void setChairs(int c) {
		NumberOfChairs = c;
	}
	void setTables(int t) {
		NumberOfTables = t;
	}
	//getters
	int getId() {
		return id;
	}
	int getFans() {
		return NumberOfFans;
	}
	int getChairs() {
		return NumberOfChairs;
	}
	int getTables() {
		return NumberOfTables;
	}
	void input() {
		cout << "Enter information" << endl;
		cout << "Enter id" << endl;
		cin >> id;
		cout << "Enter number of fans" << endl;
		cin >> NumberOfFans;
		cout << "Enter number of chair" << endl;
		cin >> NumberOfChairs;
		cout << "Enter number of tables" << endl;
		cin >> NumberOfTables;
	}
	void output() {
		cout << "Displaying information" << endl;
		cout << "Id : " << id << endl;
		cout << "Number of fans : " << NumberOfFans << endl;
		cout << "Number of chairs : " << NumberOfChairs << endl;
		cout << "Number of tables : " << NumberOfTables << endl;
	}
};
//main function
int main() {
	//objects
	ClassRoom obj1, obj2, obj3;
	obj1.input();
	obj1.output();
	system("pause");
	return 0;
}