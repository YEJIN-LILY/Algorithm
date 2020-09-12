#include <iostream>
using namespace std;

//하나의 노드 정보 선언
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

//전위순회
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위순회
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위순회
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main() {
	node nodes[16];
	for (int i = 1; i <16; i++) {
		nodes[i].data = i;
		nodes[i].leftChild =NULL;
		nodes[i].rightChild = NULL;
	}
	for (int i = 1; i < 16; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;
}
