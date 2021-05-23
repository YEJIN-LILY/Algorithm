#include <iostream>
#include <queue>
using namespace std;

int M, N,cnt;
int arr[260][260];
bool visited[260][260] = { false, };
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void bfs(int a,int b) {
	queue<pair<int, int>> q;

	q.push({ a,b });
	visited[a][b] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			else {
				if (arr[nx][ny] == 1 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout<<cnt;
}
