#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int data;

	Node(int d) {
		left = NULL;
		right = NULL;

		data = d;
	}
};

class BST {
private:
	Node* root;

public:

	BST(int d) {
		root = new Node(d);
	}

	void insert(int d) {
		Node* newNode = new Node(d);
		Node* currentNode = root;
		while (true) {
			if (currentNode->data > d) {
				if (currentNode->left == NULL) {
					currentNode->left = newNode;
					break;
				}
				currentNode = currentNode->left;
			}
			else if (currentNode->data < d) {
				if (currentNode->right == NULL) {
					currentNode->right = newNode;
					break;
				}
				currentNode = currentNode->right;
			}
			else {
				cout << "No duplicate nodes" << endl;
				break;
			}
		}
	}

	void deleteNode(int d){
		Node* currentNode = root;
		Node* parentNode = NULL;

		while(true){
			if(currentNode->data == d){
				break;
			}else if(currentNode->data > d){
				parentNode = currentNode;
				currentNode = currentNode->left;
			}else if(currentNode->data < d){
				parentNode = currentNode;
				currentNode = currentNode->right;
			}
		}

		if(currentNode->left == NULL && currentNode->right == NULL){
			if(parentNode->left == currentNode){
				delete parentNode->left;
				parentNode->left = NULL;
			}else if(parentNode->right == currentNode){
				delete parentNode->right;
				parentNode->right = NULL;
			}
		}else if(currentNode->left == NULL && currentNode->right != NULL){
			if(currentNode == root){
				root = currentNode->right;
				delete currentNode;
			}else{
				if(parentNode->right == currentNode){
					parentNode->right = currentNode->right;
					delete currentNode;
				}else if(parentNode->left == currentNode){
					parentNode->left = currentNode->right;
					delete currentNode;
				}
			}
		}else if(currentNode->left != NULL && currentNode->right == NULL){
			if(currentNode == root){
				root = currentNode->left;
				delete currentNode;
			}else{
				if(parentNode->right == currentNode){
					parentNode->right = currentNode->left;
					delete currentNode;
				}else if(parentNode->left == currentNode){
					parentNode->left = currentNode->left;
					delete currentNode;
				}
			}
		}else if(currentNode->right != NULL && currentNode->left !=	NULL){
			Node* successor = currentNode->right;
			Node* successorParent = currentNode;

			if(successor->left == NULL){
				if(currentNode == root){
					successor->left = currentNode->left;
					root = successor;
					delete currentNode;
				}else{
					if(parentNode->left == currentNode){
						parentNode->left = successor;
					}else if(parentNode->right == currentNode){
						parentNode->right = successor;
					}
					successor->left = currentNode->left;
					delete currentNode;
				}
			}else{
				while(successor->left != NULL){
					successorParent = successor;
					successor = successor->left;
				}

				if(currentNode == root){
					root = successor;
				}else{
					if(parentNode->right == currentNode){
						parentNode->right = successor;
					}else if(parentNode->left == currentNode){
						parentNode->left = successor;
					}
				}

				successor->right = currentNode->right;
				successor->left = currentNode->left;
				successorParent->left = NULL;
				delete currentNode;
			}
		}

	}

	Node* findNode(int d){
		Node* currentNode = root;

		while(true){
			if(currentNode->data == d){
				break;
			}else if(currentNode->data > d){
				if(currentNode->left != NULL){
					currentNode = currentNode->left;
				}else{
					currentNode = NULL;
					break;
				}
				
			}else if(currentNode->data < d){
				if(currentNode->right != NULL){
					currentNode = currentNode->right;				
				}else{
					currentNode = NULL;
					break;
				}
			}
		}

		return currentNode;
	}


	void printTree() {
		Node* currentNode = root;

		queue<Node*> container;

		container.push(currentNode);

		while (!container.empty()) {
			currentNode = container.front();
			container.pop();
			cout << currentNode->data << endl;


			if (currentNode->left != NULL) {
				container.push(currentNode->left);
			}

			if (currentNode->right != NULL) {
				container.push(currentNode->right);
			}
		}
	}
};


int main() {
	BST tree(10);
	tree.insert(20);
	tree.insert(5);
	tree.insert(3);
	tree.insert(24);
	tree.insert(60);
	tree.insert(18);
	tree.insert(6);

	tree.printTree();

	cout<<endl<<endl;

	tree.deleteNode(10);

	tree.printTree();

	cout<<endl<<endl;

	if(tree.findNode(60) != NULL){
		cout<<"Found"<<endl;
	}else{
		cout<<"Not found"<<endl;
	}

	system("pause");
	return 0;
}