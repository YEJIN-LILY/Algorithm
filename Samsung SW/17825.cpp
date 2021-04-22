#include <iostream>
#include <algorithm>
using namespace std;

int dice[10];
int answer;
//경우의 수가 몇 가지 안되면 그냥 배열로 다 만들자!!!
int board[4][22] = { {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0},
	{10,13,16,19,25,30,35,40,0},
	{20,22,24,25,30,35,40,0},
	{30,28,27,26,25,30,35,40,0} };

int mapIndex[4] = { 21,8,7,8 }; //도착 지점 인덱스

//line: 총 4가지의 경로로 도착점에 도달할 수 있다
struct Horse {
	bool is_arrived;
	int line;
	int index;
}horses[4];

int order[10]; //주사위 순서

void init() { //삼성 코테에서는 필요함
	for (int i = 0; i < 4; i++) {
		horses[i].is_arrived = false;
		horses[i].line = 0;
		horses[i].index = 0;
	}
}

void is_blue(int num) { //파란색 라인이면 해당 라인으로 이동해야 함
	if (horses[num].line == 0) {
		if (horses[num].index == 5) {
			horses[num].line = 1;
			horses[num].index = 0;
		}
		if (horses[num].index == 10) {
			horses[num].line = 2;
			horses[num].index = 0;
		}
		if (horses[num].index == 15) {
			horses[num].line = 3;
			horses[num].index = 0;
		}
	}
}

bool can_move(int num) { //이동할 말의 번호
	//인덱스 넘어가는지 확인: 등호!!도착지점도 인덱스에 넣어줬다
	if (horses[num].line == 0 && horses[num].index >= 21) 
		return false;
	else if (horses[num].line == 1 && horses[num].index >= 8)
		return false;
	else if (horses[num].line == 2 && horses[num].index >= 7)
		return false;
	else if (horses[num].line == 3 && horses[num].index >= 8)
		return false;
	return true;
}

bool is_there_horse(int num) {
	for (int i = 0; i < 4; i++) {
		if (num != i) { //다른 말이 내가 가려는 위치에 있는지 확인
			//line, index비교 하려 했는데 다른 경로를 통해서 말이 같은 위치에 있을 수도 있다
			if (board[horses[num].line][horses[num].index] == board[horses[i].line][horses[i].index]) { //일단 점수가 같은지 확인
				if (horses[num].line == horses[i].line) //점수 같은데 라인 같다? 무조건 같은 위치에 있음
					return true;
				if (mapIndex[horses[num].line] - 4 <= horses[num].index && mapIndex[horses[i].line] - 4 <= horses[i].index) //마지막 4개의 index가 겹친다. 여기에 있는지 확인
					return true;
			}
		}
	}
	return false;
}

void dfs(int depth) { //depth: 주사위 나온 순서: ex)0번째 주사위
	//백트래킹을 안 했기 때문에 현재 상태 저장하는 임시변수 필요없다

	if (depth == 10) { //주사위 끝까지 다 사용->최댓값 비교해서 도출
		int sum = 0;
		init(); //해당 케이스마다 초기화 해줘야 함
		for (int i = 0; i < 10; i++) { //이제 순서대로 이동시켜보자
			if (can_move(order[i])) { //이동할 수 있으면
				horses[order[i]].index += dice[i];

				if (can_move(order[i])==false) { //끝에 도달했는지 확인
					horses[order[i]].is_arrived = true;
					horses[order[i]].index = mapIndex[horses[order[i]].line];
				}
				sum += board[horses[order[i]].line][horses[order[i]].index];

				is_blue(order[i]); //파란색 길 갈 수 있는지 확인

				//말의 도착 지점에 다른 말이 있는지->성립 안되는 케이스임. 그냥 종료시켜 버리자
				if (horses[order[i]].is_arrived == false && is_there_horse(order[i]))
					return;
			}
			else //이동못한다->성립안되는 케이스
				return;
		}
		answer = max(sum, answer);
		//cout << "sum: " << sum << endl;
		//cout << "answer: " << answer<<endl;
		return;
	}

	for (int i = 0; i < 4; i++) {
		order[depth] = i; //depth번째 주사위를 i번째 말이 이동함
		dfs(depth + 1);
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	answer = 0;
	init();

	dfs(0);
	cout << answer;
}
