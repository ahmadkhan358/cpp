#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

    Node* createNewNode(int d) {
        Node* newNode = new Node();
        newNode->data = d;
        newNode->next = NULL;
        return newNode;
    }
    bool search(int d) {
        Node* container = head;
        bool isFound = false;
        while (container != NULL) {
            if (container->data == d) {
                isFound = true;
                break;
            }
            container = container->next;
        }
        return isFound;
    }

public:

    LinkedList(int d) {
        head = createNewNode(d);
        tail = head;
    }


    void append(int d) {
        if (search(d)) {
            cout << "Already present" << endl;
        }
        else {
            Node* newNode = createNewNode(d);
            tail->next = newNode;
            tail = newNode;
        }
    }

    void prepend(int d) {
        if (search(d)) {
            cout << "Already present" << endl;
        }
        else {
            Node* newNode = createNewNode(d);
            newNode->next = head;
            head = newNode;
        }
    }

    void deleteNode(int d) {
        if (search(d)) {
            Node* prevoiusContainer = NULL;
            Node* container = head;

            if (head->data == d) {
                container = head;
                head = head->next;
                delete container;
            }
            else {
                while (true) {
                    if (container->data == d) {
                        break;
                    }
                    prevoiusContainer = container;
                    container = container->next;
                }
                if (tail->data == d) {
                    tail = prevoiusContainer;
                    tail->next = NULL;
                    delete container;
                }
                else {
                    prevoiusContainer->next = container->next;
                    delete container;
                }
            }
        }
        else {
            cout << "Node not present" << endl;
        }
    }



    void printList() {
        Node* container = head;
        while (container != NULL) {
            cout << "Current Node Address : " << container << ", Data : " << container->data << ", Next Node Address : " << container->next << endl;
            container = container->next;
        }
    }

    ~LinkedList() {
        Node* container = head;
        Node* next;
        while (container != NULL) {
            next = container->next;
            delete container;
            container = next;
        }
        head = NULL;
        tail = NULL;
        cout << "End of program" << endl;
    }
};

int main() {
    LinkedList l1(8);
    l1.append(4);
    l1.append(2);
    LinkedList l2(2);
    l2.append(9);
    l2.append(1);
    l1.printList();
    l2.printList();
    l1.~LinkedList();
    l2.~LinkedList();
    system("pause");
    return 0;
}