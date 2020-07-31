#include<iostream>
using namespace std;
class Queue {
private:
	int front, rear;
	int queue_array[10];
public:
	Queue() {
		front = 0;
		rear = -1;
		for (int i = 0; i < 10; i++) {
			queue_array[i] = 0;
		}
	}
	void enqueue(int);
	int dequeue();
};
void Queue::enqueue(int val) {
	if (rear >= 9) {
		cout << "Queue is full" << endl;
	}
	else {
		queue_array[++rear] = val;
	}
}
int	Queue::dequeue() {
	if (front == 0 && rear == -1) {
		cout << "First enter data in Queue" << endl;
	}
	else {
		return queue_array[front++];
	}
}
int main() {
	Queue q; 
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	q.enqueue(8);
	q.enqueue(9);
	q.enqueue(10);
	for (int i = 0; i < 10; i++) {
		cout << q.dequeue() << endl;
	}
	system("pause");
	return 0;
}