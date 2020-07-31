#include<iostream>
using namespace std;

int binary_search(int pass_array[], int int_to_find, int l_b, int u_b) {
	int mid_point = 0;
	while (true) {
		if (u_b < l_b) {
			break;
		}

		mid_point = l_b + (u_b - l_b) / 2;

		if (pass_array[mid_point] < int_to_find) {
			l_b = mid_point + 1;
		}

		if (pass_array[mid_point] > int_to_find) {
			u_b = mid_point - 1;
		}

		if (pass_array[mid_point] == int_to_find) {
			return mid_point;
			break;
		}
	}
}

void insertion_sort(int pass_array[], int len) {
	int temp = 0;
	int j = 0;
	for (int i = 0; i < len; i++) {
		temp = pass_array[i];
		j = i - 1;

		while (j >= 0 && pass_array[j] > temp) {
			pass_array[j + 1] = pass_array[j];
			j = j - 1;
		}

		pass_array[j + 1] = temp;
	}
}

int main() {
	int values[] = { 9,8,7,6,5,4,3,2,1 };
	int length_of_array = sizeof(values) / sizeof(values[0]);
	insertion_sort(values, length_of_array);

	for (int i = 0; i < 9; i++) {
		cout << values[i] << " ";
	}
	int lower_bound = 0;
	int upper_bound = (sizeof(values) / sizeof(values[0])) - 1;
	int integer_to_find = 6;
	cout << "Number found at index " << binary_search(values, integer_to_find, lower_bound, upper_bound) << " in array" << endl;
	system("pause");
	return 0;
}