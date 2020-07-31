#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	const int n = 10;
	int open = 0, closed = 0, howManyOpen = 0;
	int door[n] = { 0,0,0,0,0,0,0,0,0,0 };

	int i = rand() % 11;

	for (int l = 1; l <= n; l++) {
		if (l == i) {
			door[l - 1] = 1;
		}
	}
	
	for (int z = 0; z < n; z++) {
		if (door[z] == 0) {
			cout << "Door# " << z + 1 << " is close" << endl;
			closed++;
		}
		else {
			cout << "Door# " << z + 1 << " is open" << endl;
			open++;
		}
	}

	cout << open << " door(s) are open" << endl;

	system("pause");
	return 0;
}