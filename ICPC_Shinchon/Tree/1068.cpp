#include <iostream>
#include <vector>
using namespace std;

int N, M,cnt,root;

struct TREENODE {
	int parent = -1;
	vector<int> children;
};

struct TREENODE tree[51];

void dfs(int n) {
	if (tree[n].parent!=-1&&tree[n].children.size() == 0) {
		cnt++;
		return;
	}
	for (int i = 0; i < tree[n].children.size(); i++) {
		if (tree[n].children[i] == M)
			continue;
		dfs(tree[n].children[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int par;
		cin >> par;
		tree[i].parent = par;
		if (par == -1) {
			root = i;
			continue;
		}
		tree[par].children.push_back(i);
	}

	cin >> M;
	
	int par = tree[M].parent;
	if (tree[par].children.size() == 1)
		cnt++;
	tree[M].parent = -1;
	tree[M].children.clear();

	dfs(root); //루트가 0이 아닐수 있음..
	cout << cnt;
}
