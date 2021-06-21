#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M;
int graph[101][101];
int answer=INF;

void floyd() {
	for (int k = 1; k <= N; k++) { //거쳐가는 노드
		for (int i = 1; i <= N; i++) { //from
			for (int j = 1; j <= N; j++) {//to
				if (i == j)
					continue;
				if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
					else
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd();

	int person = 1;

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			cnt += graph[i][j];
		}
		if (answer > cnt) {
			answer = cnt;
			person = i;
		}
	}

	cout << person;
}
