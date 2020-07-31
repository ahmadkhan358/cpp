#include<iostream>
using namespace std;
class Stack {
private: 
	int stack_array[10];
	int top;
public:
	Stack() {
		top = -1;
		for (int i = 0; i < 10; i++) {
			stack_array[i] = 0;
		}
	}
	void push(int);
	int pop();
};
void Stack::push(int val) {
	stack_array[++top] = val;
}
int Stack::pop() {
	return stack_array[top--];
}
int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);
	for (int i = 0; i < 10; i++) {
		cout << s.pop() << endl;
	}
	system("pause");
	return 0;
}