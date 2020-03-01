#include <iostream>
using namespace std;

int INF = 1000000000;

int a[4][4] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

void floydWarshall() {
	//결과 그래프
	int d[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			d[i][j] = a[i][j];
		}
	}

	//k:거쳐가는 노드. k를 중심으로 for문!!!
	for (int k = 0; k < 4; k++) {
		//i:출발 노드
		for (int i = 0; i < 4; i++) {
			//j: 도착 노드
			for (int j = 0; j < 4; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	floydWarshall();
}
