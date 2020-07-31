#include<iostream>
using namespace std;
class Base {
public:
	virtual void disp() {
		cout << "This is the function of base class" << endl;
	}
};
class Derived1 :public Base {
public :
	void disp() {
		cout << "This is the function of derived1 class" << endl;
	}
};
class Derived2 :public Base {
	void disp() {
		cout << "This is the function of derived2 class" << endl;
	}
};
int main() {
	Base* b1 = new Base;
	Derived1 d1obj;
	Derived2 d2obj;
	b1 = &d1obj;
	b1->disp();
	delete b1;
	system("pause");
	return 0;
}