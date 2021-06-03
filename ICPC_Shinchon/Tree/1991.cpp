#include <iostream>
using namespace std;

struct TreeNode {
	int parent = -1;
	int left = -1;
	int right = -1;
};

TreeNode tree[27];
int N;

void preOrder(int node) {
	cout << (char)(node+65);
	if (tree[node].left != -1)
		preOrder(tree[node].left);
	if (tree[node].right != -1)
		preOrder(tree[node].right);
}

void inOrder(int node) {
	if (tree[node].left != -1)
		inOrder(tree[node].left);
	cout << (char)(node + 65);
	if (tree[node].right != -1)
		inOrder(tree[node].right);
}

void postOrder(int node) {
	if (tree[node].left != -1)
		postOrder(tree[node].left);
	if (tree[node].right != -1)
		postOrder(tree[node].right);
	cout << (char)(node + 65);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		if(b!='.')
			tree[a - 65].left = (int)(b - 65);
		if(c!='.')
			tree[a - 65].right = (int)(c - 65);
	}

	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
}
