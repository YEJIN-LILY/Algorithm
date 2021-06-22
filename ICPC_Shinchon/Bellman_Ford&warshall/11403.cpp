#include <iostream>
using namespace std;

int graph[101][101];
int N;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] && graph[k][j]) //갱신해줘야 한다->걍 기존 graph에 갱신하면 됨
					graph[i][j] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}
