#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int N;
int parent[100001];
bool visited[100001] = { false, };

void dfs(int n) {
	visited[n] = true;

	for (int i = 0; i < tree[n].size(); i++) {
		int nxt = tree[n][i];
		if (!visited[nxt]) {
			parent[nxt] = n;
			dfs(tree[n][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}
}
