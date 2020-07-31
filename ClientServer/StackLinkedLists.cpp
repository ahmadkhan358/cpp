#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
class Stack {
private:
	node* first;
public:
	Stack() {
		first = NULL;
	}
	void push(int);
	void pop();
};
void Stack::push(int d) {
	node* temp = new node;
	temp->data = d;
	temp->next = first;
	first = temp;
}
void Stack::pop() {
	node* pop_ptr = new node;
	pop_ptr = first;
	if (pop_ptr == NULL) {
		cout << "First push a value in the stack" << endl;
	}
	else {
		first = pop_ptr->next;
		cout << pop_ptr->data << endl;
		delete pop_ptr;
	}
}
int main() {
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();
	s.pop();
	s.pop();
	system("pause");
	return 0;
}