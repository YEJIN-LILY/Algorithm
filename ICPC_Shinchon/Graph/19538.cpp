#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N,M,tmp,t;
vector<int> ppl[200001]; //연결
bool is_believe[200001] = { false, };
vector<int> ans;
queue<int> q;
vector<int> in_queue;

void update(vector<int> v) {
	t++;

	for (int i = 0; i < v.size(); i++) {
		is_believe[v[i]] = true;
		ans[v[i]] = t;
	}
}

bool check_neighbor(int num) {
	int cnt = 0;

	for (int i = 0; i < ppl[num].size(); i++) {
		int p = ppl[num][i];

		if (is_believe[p])
			cnt++;
	}

	if(cnt>= ceil((float)(float)ppl[num].size() / (float)2)) //(int/int)=>int형으로 된다. float로 바꿔주어야 함
		return true;
	else
		return false;
}

void bfs() {
	while (!q.empty()) {
		vector<int> update_ppl; //나중에 한꺼번에 갱신해야 

		for (int i = 0; i < in_queue.size(); i++) {
			tmp = in_queue[i];

			for (int i = 0; i < ppl[tmp].size(); i++) {
				int p = ppl[tmp][i];

				if (!is_believe[p] && check_neighbor(p)) {
					update_ppl.push_back(p);
				}
			}
			q.pop();
		}
		in_queue.clear();
		if (update_ppl.size() > 0) {
			update(update_ppl);
			for (int i = 0; i < update_ppl.size(); i++) {
				q.push(update_ppl[i]);
				in_queue.push_back(update_ppl[i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	ans.resize(N+1);
	for (int i = 1; i <= N; i++) {
		ans[i] = -1;
	}

	for (int i = 1; i <= N; i++) {
		while (true) {
			cin >> tmp;

			if (tmp == 0)
				break;
			ppl[i].push_back(tmp);
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		is_believe[tmp] = true;
		ans[tmp] = 0;
		in_queue.push_back(tmp);
		q.push(tmp);
	}

	
	bfs();
	
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	} 
}
