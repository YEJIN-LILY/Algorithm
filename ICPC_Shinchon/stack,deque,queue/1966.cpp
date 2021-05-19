#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T, N, M;

bool cmp(int a, int b) {
	return a < b;
}

void solution(priority_queue<int>pq,queue<int> q) {
	int cnt = 1;
	int idx = M;

	while(!q.empty()) {
		if (pq.top() == q.front()) {
			pq.pop();
			q.pop();

			if (idx == 0) {
				cout <<cnt<<"\n";
				break;
			}
			idx--;
			cnt++;
		}
		else {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
			if (idx == 0)
				idx = q.size() - 1;
			else
				idx--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;

		queue<int> q;
		priority_queue<int> pq;
		int tmp;

		for (int j = 0; j < N; j++) {
			cin >> tmp;
			q.push(tmp);
			pq.push(tmp);
		}

		solution(pq,q);
	}
}
