#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
int a, b;
char c;
vector<int> v[1001];
vector<char> dir;
bool visited[1001] = { false, };
int destination[1001];


void dfs(int start,int n,int m) {
	if (m == M-1) {
		if (dir[m] == 'L') {
			destination[start]=v[n][0];
		}
		else {
			destination[start]=v[n][1];
		}
		return;
	}
	else {
		if (dir[m] == 'L') {
			dfs(start,v[n][0], m + 1);
		}
		else {
			dfs(start,v[n][1], m + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;


	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		v[i].push_back(a);
		v[i].push_back(b);
	}
	for (int i = 0; i < M; i++) {
		cin >> c;
		dir.push_back(c);
	}

	int nxt = 1;

	for (int i = 1; i <= N; i++) { //모든 정점으로부터 최종 도착지 구함
		dfs(i, i, 0);
	}

	int cycle = 0;

	for (int i = 1; i <= N; i++) {
		cycle++;

		if (destination[nxt] == 1) {
			break;
		}
		nxt = destination[nxt];
	}

	nxt = 1;
	for (int i = 0; i < K % cycle; i++) {
		nxt = destination[nxt];
	}

	cout << nxt;

	return 0;
}
