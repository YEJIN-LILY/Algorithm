#include <iostream>
using namespace std;

struct Node {
	Node *left;
	Node *right;
	int data;
};

Node* tree=NULL;

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data < node->data) {
		node->left=insert(node->left,data);
	}
	else {
		node->right = insert(node->right, data);
	}
	return node;
}

void postOrder(Node* node) {
	if (node->left != NULL)
		postOrder(node->left);
	if (node->right != NULL)
		postOrder(node->right);
	cout << node->data << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k;
	while (cin >> k) {
		if (k == EOF)
			break;
		tree = insert(tree, k);
	}
	postOrder(tree);
}
