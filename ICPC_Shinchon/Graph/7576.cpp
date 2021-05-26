#include <iostream>
#include <queue>
using namespace std;

int M, N,cnt;
int arr[1001][1001];
bool visited[1001][1001] = { false, };
int dist[1001][1001] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
bool all_riped = true;
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M||arr[nx][ny]==-1)
				continue;
			if (arr[nx][ny] == 0 && !visited[nx][ny]) {
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1; //일수->거리 개념으로 이해하면 된다.
				visited[nx][ny] = true;
				arr[nx][ny] = 1;
			}
		}
	}
}

int answer() {
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0)
				return -1;
			if (ans < dist[i][j])
				ans = dist[i][j];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0)
				all_riped = false;
			if (arr[i][j] == 1 && !visited[i][j]) { //이미 익은 과일들을 먼저 큐에 넣어주어야 한다->이후 bfs 
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}

	bfs();

	if (all_riped)
		cout << 0;
	else
		cout << answer();

}
