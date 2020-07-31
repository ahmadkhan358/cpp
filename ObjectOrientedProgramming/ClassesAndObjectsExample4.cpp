#include<iostream>
using namespace std;
class myClass {
private:
	static int count;
	int sNo;
public:
	myClass() :sNo(0) {
		count++;
	}
	int myFunction() {
		sNo = count;
		return sNo;
	}
};
int myClass::count = 0;
int main() {
	myClass obj1;
	cout << "I am object number " << obj1.myFunction() << endl;
	myClass obj2;
	cout << "I am object number " << obj2.myFunction() << endl;
	myClass obj3;
	cout << "I am object number " << obj3.myFunction() << endl;
	system("pause");
	return 0;
}