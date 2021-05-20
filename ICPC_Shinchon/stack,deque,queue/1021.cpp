#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, M,ans;
deque<int> dq;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	int tmp;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int idx = 1;

	for (int i = 0; i < v.size(); i++) {
		idx = 1;
		for (deque<int>::iterator it = dq.begin(); it < dq.end(); it++) {
			if (*it == v[i]) {
				break;
			}
			idx++;
		}

		if (idx == 0) {
			dq.pop_front();
		}
		else {
			int left = idx - 1;
			int right = dq.size() - idx+1;

			if (left >= right) { //오른쪽 이동
				for (int k = 0; k < right; k++) {
					int tmp = dq.back();
					dq.pop_back();
					dq.push_front(tmp);
				}
				ans += right;
			}
			else { //왼쪽 이동
				for (int k = 0; k < left; k++) {
					int tmp = dq.front();
					dq.pop_front();
					dq.push_back(tmp);
				}
				ans+=left;
			}
			dq.pop_front();
		}
	}

	cout << ans;
}
