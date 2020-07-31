#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
class Queue {
private:
	node * front;
	node* rear;
public:
	Queue() {
		front = NULL;
		rear = NULL;
	}
	void enqueue(int);
	int dequeue();
};
void Queue::enqueue(int val) {
	node* temp = new node;
	temp->data = val;
	temp->next = NULL;
	if (front == NULL) {
		front = temp;
		rear = temp;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
}
int Queue::dequeue() {
	int x = 0;
	if (front == NULL) {
		cout << "First insert a value in queue" << endl;
	}
	else {
		node* ptr = new node;
		ptr = front;
		x = ptr->data;
		front = ptr->next;
		delete ptr;
	}
	return x;
}
int main() {
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	cout << q.dequeue() << endl;
	system("pause");
	return 0;
}