#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Node {
	int value;
	Node* next;
};

class linkedList {

private:
	Node* head;
	Node* tail;

public:
	linkedList() {
		head = tail = NULL;
	}

	void insert(int val) {
		Node* newNode = new Node();
		if (head == NULL && tail == NULL) {
			newNode->value = val;
			newNode->next = tail;
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->value = val;
			newNode->next = NULL;
			tail = newNode;
		}
		
	}

	Node* getHead() {
		return this->head;
	}

	void displayNodes() {
		Node* nodes = new Node();
		nodes = head;
		while (true) {
			cout << nodes->value << endl;
			if (nodes->next == NULL) {
				break;
			}
			else {
				nodes = nodes->next;
			}
		}
	}
};

class Solution {
private:
	string str1;
	string str2;
public:

	Solution() {
		str1 = str2 = "";
	}

	Node* addTwoNodes(Node* l1, Node* l2) {
		int num1, num2;
		
		while (true) {
			str1.append(to_string(l1->value));
			l1 = l1->next;

			if (l1 == NULL) {
				break;
			}
		}

		while (true) {
			str2.append(to_string(l2->value));
			l2 = l2->next;

			if (l2 == NULL) {
				break;
			}
		}


		num1 = stoi(this->reverseTheString(str1));

		num2 = stoi(this->reverseTheString(str2));

		num1 += num2;


		str1 = to_string(num1);
		str2 = this->reverseTheString(str1);
		num2 = 0;

		linkedList L;

		while (num2 < str2.length()) {

			L.insert(((int)str2[num2])-48);
			num2++;
		}

		return L.getHead();
	}

	string reverseTheString(string str) {
		reverse(str.begin(), str.end());
		return str;
	}
};


int main() {
	linkedList l1;
	linkedList l2;

	l1.insert(2);
	l1.insert(4);
	l1.insert(3);

	l2.insert(5);
	l2.insert(6);
	l2.insert(4);

	Solution s1;
	Node* ptr = new Node();
	ptr = s1.addTwoNodes(l1.getHead(), l2.getHead());

	while (true) {
		cout << ptr->value;
		ptr = ptr->next;

		if (ptr == NULL) {
			break;
		}
		cout << "->";
	}
	cout << endl;

	system("pause");
	return 0;
}