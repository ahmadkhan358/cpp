#include<iostream>
using namespace std;

int main() {
	int values[] = { 10,9,8,7,6,5,4,3,2,1,0 };
	int input = 0;
	int i = 0, temp = 0;

	cout << "Enter the number to search in array" << endl;
	cin >> input;

	for (i = 0; i < 11; i++) {
		if (input == values[i]) {
			temp = 1;
			break;
		}
	}

	if (temp == 1) {
		cout << "Number found in array at index " << i << endl;
	}
	else {
		cout << "Number not found in array" << endl;
	}

	system("pause");
	return 0;
}