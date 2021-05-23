#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[65][65];
bool visited[65][65] = { false, };
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

bool bfs(int a, int b) {
	queue<pair<int, int>> q;

	visited[a][b] = true;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int nx = x;
		int ny = y;

		for (int k = 0; k < 2; k++) {
			if (k == 0) { //아래
				nx = x + arr[x][y];
				ny = y;
			}
			else { //오른쪽
				nx = x;
				ny = y + arr[x][y];
			}

			if (nx >= N || ny >= N) {
				continue;
			}
			else if (arr[nx][ny] == -1)
				return true;
			else {
				if (visited[nx][ny] == false) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
		
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	if (bfs(0, 0))
		cout << "HaruHaru";
	else
		cout << "Hing";
}
