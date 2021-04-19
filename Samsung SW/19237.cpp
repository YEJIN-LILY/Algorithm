#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Shark { //위, 아래, 왼, 오른
	int state;
	int direction[4][4];
}sharks[401];

struct Info {
	int shark_num;
};

struct Point {
	int x, y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int N, M, K, sec;
int num;
int board[21][21];
pair<int, int> smell[21][21]; //상어 번호, 냄새 시간
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void decrease_smell() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (smell[i][j].second != 0) {
				smell[i][j].second--;

				if (smell[i][j].second == 0) {
					smell[i][j].first = 0;
				}
			}
		}
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void move() {//상어 이동
	vector<Info> tmp[21][21];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] != 0) {//상어 있음
				int shark_num = board[i][j];
				int shark_state = sharks[shark_num].state; //상어 현재 상태
				bool is_move = false;

				vector<pair<Point, int>> v; //자기 냄새 있는 곳 저장{좌표,이동방향}
				for (int k = 0; k < 4; k++) {
					int newX = i + dx[sharks[shark_num].direction[shark_state][k]]; //상어 이동 우선순위에 따른 인덱스
					int newY = j + dy[sharks[shark_num].direction[shark_state][k]];

					if (newX <= 0 || newY <= 0 || newX > N || newY > N)
						continue;
					if (smell[newX][newY].first == shark_num) { //냄새 없는 칸을 못찾을 경우 대비->자신의 냄새있는 곳으로 이동해야 함
						Point p(newX, newY);
						v.push_back({ p,sharks[shark_num].direction[shark_state][k] }); //좌표, 이동 방향
					} 
					if (smell[newX][newY].second == 0) { //냄새 없는 곳 찾음
						is_move = true;
						tmp[newX][newY].push_back({ shark_num }); //일단 이동한다음 갱신해야 하기 때문에 임시 벡터에 옮긴다!!
						sharks[shark_num].state = sharks[shark_num].direction[shark_state][k];
						board[i][j] = 0;
						break;
					}
				}
				if (is_move == false) { //냄새 없는 칸 찾지 못함->자기 냄새 있는 곳으로 감
					if (!v.empty()) {
						int x = v[0].first.x;
						int y = v[0].first.y;
						tmp[x][y].push_back({ shark_num });
						sharks[shark_num].state = v[0].second;
					}
				}
				board[i][j] = 0;
			}
		}
	} //상어 모두 이동시켰음(임시배열에)

	for (int i = 1; i <= N; i++) { //상어 실제로 이동
		for (int j = 1; j <= N; j++) {
			if (tmp[i][j].size() >= 2) {
				int n = M + 1;
        //M값이 변하면 n도 변한다!!!!!!M을 num 변수에 옮겨주자ㅠㅠㅠㅠ
				num -= (tmp[i][j].size() - 1); //상어 쫒겨남
				for (int k = 0; k < tmp[i][j].size(); k++) {
					if (n > tmp[i][j][k].shark_num) {
						n = tmp[i][j][k].shark_num;
					}
				}
				board[i][j] = n;
				smell[i][j].first = n;
				smell[i][j].second = K + 1;
			}
			else if (tmp[i][j].size() == 1) {
				board[i][j] = tmp[i][j][0].shark_num;
				smell[i][j].first = tmp[i][j][0].shark_num;
				smell[i][j].second = K + 1;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	num = M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				smell[i][j].first = board[i][j];
				smell[i][j].second = K + 1;
			}
			else {
				smell[i][j].first = 0;
				smell[i][j].second = 0;
			}
		}
	}

	for (int i = 1; i <= M; i++) { //상어 정보 저장
		cin >> sharks[i].state;
		sharks[i].state--; //인덱스 0부터 사용할것임
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> sharks[i].direction[j][k]; //우선순위 저장
				sharks[i].direction[j][k]--;
			}
		}
	}

	while (sec < 1000) {
		sec++;
		decrease_smell(); //5초가 되어서 smell값이 0이면 상어가 이동할 수 있다->decrease부터 해주자
		move();

		if (num == 1) { //상어 한마리->1번 상어만 있음
			cout << sec << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

