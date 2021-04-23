#include <iostream>
#include <vector>
using namespace std;

int N, K,answer,is_finish;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

struct Horse {
	int direction;
	int x, y;
	int num;
	int index; //보드 칸에서 몇 번째로 있는지
}horses[11];

vector<Horse> board[13][13];
int color_board[13][13];

void init() {
	for (int i = 0; i < 11; i++) {
		horses[i].direction = 0;
		horses[i].num = i;
		horses[i].x = 0;
		horses[i].y = 0;
		horses[i].index = 0;
	}
	answer = 0;
	is_finish = false;
}

void move() { //말 이동
	for (int i = 1; i <= K; i++) {
		int newX = horses[i].x + dx[horses[i].direction];
		int newY = horses[i].y + dy[horses[i].direction];

		if (newX <= 0 || newY <= 0 || newX > N || newY > N|| color_board[newX][newY] == 2) { //인덱스 벗어나거나 이동하려는 칸이 파란색이면
			if (horses[i].direction == 0) {
				horses[i].direction = 1;
			}
			else if (horses[i].direction == 1) {
				horses[i].direction = 0;
			}
			else if (horses[i].direction == 2) {
				horses[i].direction = 3;
			}
			else if (horses[i].direction == 3) {
				horses[i].direction = 2;
			}
			newX= horses[i].x + dx[horses[i].direction];
			newY= horses[i].y + dy[horses[i].direction];

			if (newX <= 0 || newY <= 0 || newX > N || newY > N || color_board[newX][newY] == 2) //이동하려는 칸이 파란색이면 이동하지 않음
				continue;
      //방향 바꾸고 이동하는 칸이 하얀색, 빨간색일 수도 있다!!!케이스 잘 나누자ㅠㅠㅠ
			else if(color_board[newX][newY]==0){ //하얀색
				//기존 보드판에서 위치하고 있던 인덱스
        //갱신할 때 참조하는 값이 바뀌지 않는지 주의하자. 왠만하면 참조하는 값은 변수 따로 설정하자
				int tmp = horses[i].index; //해당 말이 몇 번째로 있는지
				int finish = board[horses[i].x][horses[i].y].size() - 1; //해당 말이 있는 판의 마지막 말의 인덱스
				int original_x = horses[i].x;
				int original_y = horses[i].y;

				for (int j = tmp; j <= finish; j++) { 
					int horse_num = board[original_x][original_y][j].num;
					board[newX][newY].push_back(horses[horse_num]); //옮겨줌
					horses[horse_num].x = newX;
					horses[horse_num].y = newY;
					horses[horse_num].index = board[newX][newY].size() - 1;
				}

				for (int j = finish; j >= tmp; j--) {
					board[original_x][original_y].pop_back(); //기존 위치에서 빼줌
				}	
			}
			else if (color_board[newX][newY] == 1) { //빨간색
				int tmp = horses[i].index;
				int finish = board[horses[i].x][horses[i].y].size() - 1;
				int original_x = horses[i].x;
				int original_y = horses[i].y;

				for (int j = finish; j >= tmp; j--) { //방향 바꿔야 하니까 finish
					int horse_num = board[original_x][original_y][j].num;
					board[newX][newY].push_back(horses[horse_num]); //옮겨줌
					horses[horse_num].x = newX;
					horses[horse_num].y = newY;
					horses[horse_num].index = board[newX][newY].size() - 1;
				}

				for (int j = finish; j >= tmp; j--) {
					board[original_x][original_y].pop_back(); //기존 위치에서 빼줌
				}
			}
		}
		else if (color_board[newX][newY] == 0) { //하얀색
			int tmp = horses[i].index;
			int finish = board[horses[i].x][horses[i].y].size() - 1;
			int original_x = horses[i].x;
			int original_y = horses[i].y;

			for (int j = tmp; j <= finish; j++) {
				int horse_num = board[original_x][original_y][j].num;

				board[newX][newY].push_back(horses[horse_num]); //옮겨줌
				horses[horse_num].x = newX;
				horses[horse_num].y = newY;
				horses[horse_num].index = board[newX][newY].size() - 1;
			}

			for (int j = finish; j >= tmp; j--) {
				board[original_x][original_y].pop_back(); //기존 위치에서 빼줌
			}
		}
		else if (color_board[newX][newY] == 1) { //빨간색
			int tmp = horses[i].index;
			int finish = board[horses[i].x][horses[i].y].size() - 1;
			int original_x = horses[i].x;
			int original_y = horses[i].y;

			for (int j = finish; j >= tmp; j--) {
				int horse_num = board[original_x][original_y][j].num;
				board[newX][newY].push_back(horses[horse_num]); //옮겨줌
				horses[horse_num].x = newX;
				horses[horse_num].y = newY;
				horses[horse_num].index = board[newX][newY].size() - 1;
			}

			for (int j = finish; j >= tmp; j--) {
				board[original_x][original_y].pop_back(); //기존 위치에서 빼줌
			}
		}
		if (board[newX][newY].size() >= 4) { //2+3개가 만나서 5개가 될수도 있다!!! 4개 '이상'이면 종료한다
			is_finish = true;
			return;
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	init();

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> color_board[i][j];
	}

	for (int i = 1; i <= K; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		horses[i].direction = dir - 1;
		horses[i].x = x;
		horses[i].y = y;
		horses[i].index = 0;
		horses[i].num = i;
		board[x][y].push_back(horses[i]);
	}

	while (answer < 1000) {
		answer++;
		move();

		if (is_finish) {
			cout << answer;
			return 0;
		}
	}
	cout << -1;
}
