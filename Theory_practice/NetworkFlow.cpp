#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100
#define INF 1000000000
using namespace std;

int n = 6;
int result;
int capacity[MAX][MAX]; //용량
int flow[MAX][MAX]; //유량
int d[MAX]; //방문여부
vector<int> a[MAX]; //간선정보

void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1); //-1로 초기화
		queue<int> q;
		q.push(start);
		while (!q.empty()) { //BFS
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				//방문하지 않은 노드 중에서 용량이 남은 경우
				if (capacity[x][y] - flow[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; //경로기억
					if (y == end)
						break;
				}
			}
		}
		if (d[end] == -1) //모든 경로를 다 찾은 경우
			break;
		int n_flow = INF;
		for (int i = end; i != start; i = d[i]) {
			n_flow = min(n_flow, capacity[d[i]][i] - flow[d[i]][i]);
		}
		//최소 유량만큼 추가
		for (int i = end; i != start; i = d[i]) {
			flow[d[i]][i] += n_flow;
			flow[i][d[i]] -= n_flow;
		}
		result += n_flow;
	}
}

int main() {
	a[1].push_back(2);
	a[2].push_back(1);
	capacity[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	capacity[1][4] = 11;


	a[2].push_back(3);
	a[3].push_back(2);
	capacity[2][3] = 6;

	a[2].push_back(5);
	a[5].push_back(2);
	capacity[1][4] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	capacity[1][4] = 11;

	a[2].push_back(4);
	a[4].push_back(2);
	capacity[2][4] = 3;

	//...
}
