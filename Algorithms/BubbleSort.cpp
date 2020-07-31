#include<iostream>
using namespace std;

int main(){
	int values[] = { 9,6,1,4,0,2,7,5,3,8 };
	int temp;

	cout << endl << "Array before sort" << endl;
	for (int i = 0; i < 10; i++) {
		cout << values[i] << " ";
	}

	for (int j = 0; j < 10; j++) {
		for (int k = j + 1; k < 10; k++) {
			if (values[j] > values[k]) {
				temp = values[j];
				values[j] = values[k];
				values[k] = temp;
			}
		}
	}

	cout << endl << "Array after sort" << endl;
	for (int k = 0; k < 10; k++) {
		cout << values[k] << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}