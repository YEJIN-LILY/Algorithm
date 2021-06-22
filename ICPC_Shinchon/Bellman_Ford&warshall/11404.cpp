#include <iostream>
#define INF 987654321
using namespace std;

int N, m;
int graph[101][101];

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> m;

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INF;
		}
	}
	int from, to, cost;

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;

		graph[from][to] = min(cost,graph[from][to]);
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}
