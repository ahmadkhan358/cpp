#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, int> values;
int calculationsNotEfficient = 0;
int calculationsEfficient = 0;

vector<int> twoSumNotEfficient(int arr[], int target, int size) {
	vector<int> reqNums;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			calculationsNotEfficient++;
			if (arr[i] + arr[j] == target) {
				reqNums.push_back(arr[i]);
				reqNums.push_back(arr[j]);
				break;
			}
		}
	}

	return reqNums;
}

vector<int> twoSumEfficient(int arr[], int target, int size) {
	int complement;
	vector<int> reqNums;

	for (int i = 0; i < size; i++) {
		calculationsEfficient++;
		values[arr[i]] = i;
	}

	for (int j = 0; j < size; j++) {
		calculationsEfficient++;
		complement = target - arr[j];
		if (values.find(complement) != values.end()) {
			reqNums.push_back(arr[j]);
			reqNums.push_back(complement);
			break;
		}
	}

	return reqNums;
}



int main() {

	int values[] = { 44,2,0,35,81,23,90,66,7,132,77,22,19 };
	int size = sizeof(values) / sizeof(int);

	vector<int> nums = twoSumEfficient(values, 97, size);

	if (nums.size() == 0) {
		cout << "Numbers not found" << endl;
	}
	else {
		cout << "[" << nums[0] << ", " << nums[1] << "]" << endl;
		cout << calculationsEfficient << endl;
	}

	nums = twoSumNotEfficient(values, 97, size);

	if (nums.size() == 0) {
		cout << "Numbers not found" << endl;
	}
	else {
		cout << "[" << nums[0] << ", " << nums[1] << "]" << endl;
		cout << calculationsNotEfficient;
		cout << calculationsEfficient << endl;
	}

	system("pause");
	return 0;
}