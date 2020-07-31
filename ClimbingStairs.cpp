#include<iostream>
#include<unordered_map>;

using namespace std;

int calculations = 0;
int calculations2 = 0;
unordered_map<int, int> memoized;

int climbStairs(int currentStep, int numberOfSteps) {
	calculations++;

	if(memoized.find(currentStep) != memoized.end()) {
		return memoized[currentStep];
	}
	else {
		if (currentStep > numberOfSteps) {
			return 0;
		}

		if (currentStep == numberOfSteps) {
			return 1;
		}
		memoized[currentStep] = climbStairs(currentStep + 1, numberOfSteps) + climbStairs(currentStep + 2, numberOfSteps);
		return memoized[currentStep];
	}
}

int climbStairs2(int currentStep, int numberOfSteps) {
	calculations2++;
	if (currentStep > numberOfSteps) {
		return 0;
	}

	if (currentStep == numberOfSteps) {
		return 1;
	}
	return climbStairs2(currentStep + 1, numberOfSteps) + climbStairs2(currentStep + 2, numberOfSteps);
}



int main() {

	cout << climbStairs2(0, 20) << endl;
	cout << calculations2 << endl;

	cout << climbStairs(0, 20) << endl;
	cout << calculations << endl;

	for (auto iterative = memoized.begin(); iterative != memoized.end(); iterative++) {
		cout << iterative->first << "\t\t" << iterative->second << endl;
	}

	system("pause");
	return 0;
}