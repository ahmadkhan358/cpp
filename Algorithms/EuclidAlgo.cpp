#include<iostream>
using namespace std;

int main() {
	int m = 80;
	int n = 24;
	int r = 0;

	while (true) {

		if (n == 0) {
			cout << "GCD is: " << m << endl;
			break;
		}

		r = m % n;

		m = n;
		n = r;
	}

	system("pause");
	return 0;
}