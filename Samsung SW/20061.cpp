#include <iostream>
using namespace std;

int N,t,x,y,score,sum;
bool board[10][10] = {true,}; //0~3행, 0~3열: 빨간색. 0~3행, 4열~9열: 파란색. 4행~9행. 0~3열: 초록색
int dx[3] = { 0,0,1 };
int dy[3] = { 0,1,0 };

void replace_green(int row) {
	for (int i = row; i >= 4; i--) {
		for (int j = 0; j < 4; j++) {
			if (i == 4) {
				board[i][j] = true;
			}
			else
				board[i][j] = board[i - 1][j];
		}
	}
}

void replace_blue(int col) {
	for (int j = col; j >= 4; j--) {
		for (int i = 0; i < 4; i++) {
			if (j == 4) {
				board[i][j] = true;
			}
			else
				board[i][j] = board[i][j-1];
		}
	}
}

void check_blue() {
	for (int j = 4; j < 10; j++) {
		bool can_delete = true;

		for (int i = 0; i < 4; i++) {
			if (board[i][j]) {
				can_delete = false;
				break;
			}
		}
		if (can_delete) {
			score++;
			replace_blue(j);
		}
	}
	//연한 칸 확인
	int cnt = 0;
	for (int j = 4; j <= 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (board[i][j] == false) {
				cnt++;
				break;
			}
		}
	}

	if (cnt == 1)
		replace_blue(9);
	else if (cnt == 2) {
		for (int j = 9; j >= 4; j--) {
			for (int i = 0; i < 4; i++) {
				if (j == 4 || j == 5) {
					board[i][j] = true;
				}
				else
					board[i][j] = board[i][j-2];
			}
		}
	}
}

void check_green() {
	for (int i = 4; i < 10; i++) {
		bool can_delete = true;

		for (int j = 0; j < 4; j++) {
			if (board[i][j]) {
				can_delete = false;
				break;
			}
		}
		if (can_delete) {
			score++;
			replace_green(i);
		}
	}

	//연한 칸 확인
	int cnt = 0;
	for (int i = 4; i <= 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == false) {
				cnt++;
				break;
			}
		}
	}
	if (cnt == 1)
		replace_green(9);
	else if (cnt == 2) {
		for (int i = 9; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				if (i == 4 || i == 5) {
					board[i][j] = true;
				}else
					board[i][j] = board[i - 2][j];
			}
		}
	}
}

void go_blue() {
	if (t == 1) {
		int idx = y;
		for (int i = 4; i < 10; i++) {
			if (board[x][i] == false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[x][idx] = false;
	}
	if (t == 2) {
		int idx = y+1;
		for (int i = 4; i < 10; i++) { //가로 블럭에서 오른쪽 상자 기준
			if (board[x][i] == false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[x][idx] = false;
		board[x][idx - 1] = false;
	}
	if (t == 3) { //세로 블럭에서 위 상자 기준
		int idx = y;
		for (int i = 4; i < 10; i++) {
			if (board[x][i] == false || board[x + 1][i] == false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[x][idx] = false;
		board[x + 1][idx] = false;
	}
	check_blue();
}

void go_green() {
	if (t == 1) {
		int idx = x;
		for (int i = 4; i < 10; i++) {
			if (board[i][y] == false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[idx][y] = false;
	}
	if (t == 2) {
		int idx = x;
		for (int i = 4; i < 10; i++) { //가로 블럭에서 왼쪽 상자 기준
			if (board[i][y] == false||board[i][y+1]==false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[idx][y] = false;
		board[idx][y+1] = false;
	}
	if (t == 3) {
		int idx = x+1;
		for (int i = 4; i < 10; i++) { //세로 블럭에서 아래쪽 상자 기준
			if (board[i][y] == false) {
				idx = i-1;
				break;
			}
			idx = i;
		}
		board[idx][y] = false;
		board[idx-1][y] = false;
	}
	check_green();
}

void set_block() {
	if (t == 1) { // 1*1
		go_blue();
		go_green();
	}
	if (t == 2) { // 1*2(가로)
		go_blue();
		go_green();
	}
	if (t == 3) { // 2*1(세로)
		go_blue();
		go_green();
	}
}

void getSum() {
	for (int i = 4; i < 10; i++) { //초록색
		for (int j = 0; j < 4; j++) {
			if (board[i][j]==false)
				sum++;
		}
	}
	for (int i = 0; i < 4; i++) { //파란색
		for (int j = 4; j < 10; j++) {
			if (board[i][j]==false)
				sum++;
		}
	}
}

void getScore() {

}

void print() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			board[i][j] = true;
	}

	for (int i = 4; i < 10; i++) { //원래 없는 블록들
		for (int j = 4; j < 10; j++)
			board[i][j] = false;
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		set_block();
	}

	cout << score << '\n';
	getSum();
	cout << sum;
}
