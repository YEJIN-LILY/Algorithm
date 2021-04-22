#include <iostream>
#include <cmath>
using namespace std;

int N, M, T;
double board[51][51]; //원판번호, 적혀있는 숫자
//적혀있는 숫자 순서: (0,1)에서 시작. 시계방향: 어차피 방향 의미없었음

struct Node {
	int x, d, k;
};

Node info[51];

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void init() {
	for (int i = 0; i < 51; i++) {
		info[i].x = 0;
		info[i].d = 0;
		info[i].k = 0;
	}
}

bool exist_Number() { //원판에 숫자 남아있는지 체크
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 0)
				return true;
		}
	}
	return false;
}

void clockWise(int num) { //시계방향
	double tmp_board[51][51];

	for (int i = 0; i < M; i++) {
		int nIndex = (i + 1) % M; //원이니까 모듈러 연산 수행!!
		tmp_board[num][nIndex] = board[num][i];
	}

	for (int i = 0; i < M; i++) {
		board[num][i] = tmp_board[num][i];
	}
}

void anti_clockWise(int num) {
	double tmp_board[51][51];

	for (int i = M-1; i >=0; i--) {
		if (i == 0) {
			tmp_board[num][M - 1] = board[num][i];
		}
		else {
			int nIndex = (i - 1) % M;
			tmp_board[num][nIndex] = board[num][i];
		}
	}

	for (int i = 0; i < M; i++) {
		board[num][i] = tmp_board[num][i];
	}
}

void getAverage() {
	double sum = 0;
	double cnt = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 0) {
				sum += board[i][j];
				cnt++;
			}
		}
	}

	double avg = sum/cnt;


	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] != 0) {
				if (board[i][j] > avg) {
					board[i][j]--;
				}

				else if (board[i][j] < avg)
					board[i][j]++;
			}
		}
	}
}

void delete_Number() {
	bool can_delete[51][51];
	bool flag = false;

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			can_delete[i][j] = false;
		}
	}

	for (int num = 1; num <= N; num++) {
		for (int i = 0; i < M; i++) { //같은 원판
			if (board[num][i] != 0) {
				if (board[num][i % M] == board[num][(i + 1) % M]) { //자기 오른쪽만 검사해도 된다. 어차피 순환할 거니까! ***바로 갱신하면 안된다!!!***
					can_delete[num][i % M] = true;
					can_delete[num][(i + 1) % M] = true;
					flag = true;
				}
			}
		}
	}
	

	//다른 원판
	for (int j = 0; j < M; j++) {
		for (int pan = 1; pan < N; pan++) {
			if (board[pan][j] != 0) {
				if (board[pan][j] == board[pan + 1][j]) {
					can_delete[pan][j] = true;
					can_delete[pan+1][j] = true;
					flag = true;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (can_delete[i][j]) {
				board[i][j] = 0;
			}
		}
	}

	if (flag == false) { //인접한 숫자 없으면
		getAverage();
	}
}


void rotate() {
	for (int i = 0; i < T; i++) {
		int X = info[i].x;

		for (int j = 0; j < info[i].k; j++) { //for문 순서 주의! 1번 회전 시 원판 모두 찾기
			for (int pan = 1; pan <= N; pan++) {
				if (pan % X == 0) {
					if (info[i].d == 0) {
						clockWise(pan);
					}else
						anti_clockWise(pan);
				}
			}
		}

		if (exist_Number()) { //회전 끝나면
			delete_Number();
		}
	}
}

int getSum() {
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			sum += board[i][j];
		}
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	init();

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> info[i].x >> info[i].d >> info[i].k;
	}

	rotate();
	cout << getSum();
}
