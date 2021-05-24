#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int arr[101][101];
int dist[101][101] = { 0, };
bool visited[101][101] = { false, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bfs(int a, int b) {
	visited[a][b] = true;
	queue<pair<int, int>> q;
	q.push({ a,b });

	dist[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//cout << x << ' ' << y << endl;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx > N || ny > M||nx<=0||ny<=0)
				continue;
			else if (arr[nx][ny] == 1 && !visited[nx][ny]) {
				dist[nx][ny] = dist[x][y] + 1; //지금까지의 지나온 경로 칸 수를 기록하는 배열이 필요하다
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}

	return dist[N][M];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	cout<<bfs(1, 1);
}
