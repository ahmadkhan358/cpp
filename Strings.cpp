#include<iostream>
#include<string> //for using string functions
using namespace std;
class String {
public:
	void strConcat(string a,string b) {
		a.append(b);
		cout << a << endl;
	}
	void strCopy(string a, string b) {
		a.copy(b);
		cout << a << endl;
	}
	void strLength(string l) {
		cout << l.length() << endl;
	}
	void strSize(string s) {
		cout << sizeof(s) << endl;
	}
	void strInsert(string str,int loc,string str2) {
		str.insert(loc, str2);
		cout << str << endl;
	}
};
int main() {
	string str1 = "Bjarne";
	string str2 = "Stroustrup";
	String s1;
	s1.strConcat(str1, str2);
	s1.strCopy(str1, str2);
	s1.strLength(str1);
	s1.strSize(str1);
	s1.strInsert(str1, 4, str2);
	system("pause");
	return 0;
}