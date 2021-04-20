#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[4][4]; //물고기 번호: 상어는 -1로 표시->물고기가 없을 수도 있으니까 0은 안된다
int a, b,newX,newY,answer;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};

struct Fish {
	int x, y;
	int direction;
	bool is_live;
}fishes[17];

void rotate(int num) {
	int dir = (fishes[num].direction+1)%8; //순환한다!!!모듈러 연산 수행
	newX = fishes[num].x + dx[dir];
	newY = fishes[num].y + dy[dir];
	fishes[num].direction = dir;
}

void move() {
	for (int i = 1; i <= 16; i++) { //물고기 이동
		if (fishes[i].is_live == false) //죽은 물고기->패스
			continue;
		bool flag = true;
		int cnt = 0;
		newX = fishes[i].x + dx[fishes[i].direction];
		newY = fishes[i].y + dy[fishes[i].direction];

		while (newX < 0 || newY < 0 || newX>3 || newY>3 || board[newX][newY] == -1) { //이동할 수 없음->회전
			if (cnt == 8) {
				flag = false; //다 회전해도 이동할 수 있는 칸이 없음: 그대로 
				break;
			}
			rotate(i);
			cnt++;
		}
		if (flag==true) {
			int tmp_x = fishes[i].x;
			int tmp_y = fishes[i].y;
			int tmp_dir = fishes[i].direction;

			if (board[newX][newY] != 0) { //swap: 물고기 있음
				int tmp_num = board[newX][newY];

				//보드 갱신
				board[tmp_x][tmp_y] = board[newX][newY];
				board[newX][newY] = i;

				//물고기 정보 갱신
				fishes[i].x = newX;
				fishes[i].y = newY;
				fishes[tmp_num].x = tmp_x;
				fishes[tmp_num].y = tmp_y;
			}
			else { //빈칸
				board[newX][newY] = i;
				board[tmp_x][tmp_y] = 0;
				fishes[i].x = newX;
				fishes[i].y = newY;
			}
		}
	}
}

void dfs(int x,int y,int dir,int sum) { //상어 현재위치, 상어방향, 물고기 합
	//백트래킹 시 필요한 임시 변수들
	Fish tmp_fishes[17];
	int tmp_board[4][4];

	//기존 상태 복사
	for (int i = 1; i <= 16; i++) {
		tmp_fishes[i].x = fishes[i].x;
		tmp_fishes[i].y = fishes[i].y;
		tmp_fishes[i].direction = fishes[i].direction;
		tmp_fishes[i].is_live = fishes[i].is_live;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp_board[i][j] = board[i][j];
		}
	}

	move(); //물고기 이동

	//상어 이동
	int nx, ny;

	for (int i = 1; i <= 3; i++) { //어차피 최대 3번까지밖에 이동하지 못함
		nx = x+dx[dir]*i;
		ny = y+dy[dir]*i;

		if (nx < 0 || ny < 0 || nx>3 || ny>3) { //인덱스 벗어난다는 것은 더 이상 진행하지 못한다는 뜻->continue가 아니라 break로 빠져나와야 한다
			break;
		}

		if (board[nx][ny] == 0) //비어있음: 갈 수 없다
			continue;

		//물고기 먹음
		int fish = board[nx][ny]; //먹을 물고기
		fishes[fish].is_live = false;
		int nDir = fishes[fish].direction;
		fishes[fish].direction = -1;
		board[nx][ny] = -1; //상어 이동
		board[x][y] = 0;

		dfs(nx, ny, nDir, sum + fish); //다시 dfs 수행
		
		//먹지 않았을 경우
		//원상태로
		fishes[fish].is_live = true;
		fishes[fish].direction = nDir;
		board[nx][ny] = fish;
		board[x][y] = -1;
	}
	
	//끝까지 도달했음->sum 도출. 이를 수행하면서 board, fish배열이 망가진 상태. 원상태로 복구해주자
	//원래대로
	for (int i = 1; i <= 16; i++) {
		fishes[i].x = tmp_fishes[i].x;
		fishes[i].y = tmp_fishes[i].y;
		fishes[i].direction = tmp_fishes[i].direction;
		fishes[i].is_live = tmp_fishes[i].is_live;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = tmp_board[i][j];
		}
	}

	answer = max(answer, sum);

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			board[i][j] = a;
			fishes[a].x = i;
			fishes[a].y = j;
			fishes[a].is_live = true;
			fishes[a].direction = b - 1;
		}
	}

	int num = board[0][0];
	int dir = fishes[num].direction;
	fishes[num].is_live = false;
	fishes[num].direction = -1;

	board[0][0] = -1;
	dfs(0, 0, dir, num); //일단 (0,0)에 있는 물고기를 먹기 때문에 적어도 그 물고기 만큼은 답이 나온다...
	cout << answer;
}
