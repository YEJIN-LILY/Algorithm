#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[101][101] = { 0, };
bool visited[101] = { false, };

int bfs(int n) {
	queue<int> q;
	visited[n] = true;
	q.push(n);

	int cnt = 0;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (!visited[i] && arr[tmp][i] == 1) {
				visited[i] = true;
				q.push(i);
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	cout << bfs(1);
}
