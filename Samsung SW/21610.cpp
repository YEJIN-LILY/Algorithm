#include <iostream>
#include <vector>
using namespace std;

int T,N,M;
int A[101][101];
int dx[8] = { 0,-1,-1,-1,0,1,1,1 }; //행
int dy[8] = { -1,-1,0,1,1,1,0,-1 }; //열
vector<pair<int,int>> v; //first-1 방향으로 second칸만큼 이동
bool cloud[101][101];
int diagnol_dx[4] = { -1,-1,1,1 };
int diagnol_dy[4] = { -1,1,-1,1 };

void make_cloud() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] >= 2 && !cloud[i][j]) {
				cloud[i][j] = true;
				A[i][j] -= 2;
			}
			else if (cloud[i][j])
				cloud[i][j] = false;
		}
	}
}

void bug() {
	int nx, ny;
	int tmp[101][101];

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			tmp[i][j] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cloud[i][j]) {
				int cnt = 0;

				for (int k = 0; k < 4; k++) {
					nx = i + diagnol_dx[k];
					ny = j + diagnol_dy[k];

					if (nx <= 0 || nx > N || ny <= 0 || ny > N)
						continue;
					if (A[nx][ny] > 0)
						cnt++;
				}
				tmp[i][j] += cnt;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			A[i][j] += tmp[i][j];
		}
	}
}

void raining() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cloud[i][j]) {
				A[i][j]++;
			}
		}
	}
}

void move_cloud(int n) {
	int dir = v[n].first-1;
	int step = (v[n].second)%N;

	int nx, ny;

	bool tmp[101][101];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			tmp[i][j] = false;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (cloud[i][j]) {
				nx = i + dx[dir] * step;
				ny = j + dy[dir] * step;

				if (nx <= 0)
					nx += N;
				else if (nx > N)
					nx -= N;

				if (ny <= 0)
					ny += N;
				else if (ny > N)
					ny -= N;

				tmp[nx][ny] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cloud[i][j] = tmp[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M; //M: 이동 횟수

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			cloud[i][j] = false;
		}
	}

	cloud[N][1] = true;
	cloud[N][2] = true;
	cloud[N - 1][1] = true;
	cloud[N - 1][2] = true;

	for (int i = 0; i < M; i++) {
		int d, s;
		cin >> d >> s;

		v.push_back({ d,s });
	}

	for (int i = 0; i < M; i++) {
		move_cloud(i);
		raining();
		bug();
		make_cloud();
	}

	int answer = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += A[i][j];
		}
	}

	cout << answer;
}
