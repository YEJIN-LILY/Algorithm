#include <iostream>
#include <vector>
using namespace std;

int N,ans,end_node;
vector<pair<int, int>> tree[10001]; //{연결 정점, weight}
bool visited[10001] = { false, };

void dfs(int node,int weight) {
	if (visited[node])
		return;
	visited[node] = true;

	if (ans < weight) {
		ans = weight;
		end_node = node;
	}
	for (int i = 0; i < tree[node].size(); i++) {
		dfs(tree[node][i].first, tree[node][i].second + weight);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	int parent, child, weight;

	for (int i = 0; i < N - 1; i++) {
		cin >> parent >> child >> weight;
		tree[parent].push_back({ child,weight });
		tree[child].push_back({ parent,weight });
	}

	dfs(1, 0); //루트로부터 가장 멀리 있는 정점 구하기

	for (int i = 0; i < 10001; i++) {
		visited[i] = false;
	}
	ans = 0;
	dfs(end_node, 0); //위에서 구한 점으로부터 가장 멀리 있는 정점 구하기

	cout << ans;
}
