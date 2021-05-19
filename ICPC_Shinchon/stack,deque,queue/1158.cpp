#include <iostream>
#include <deque>
using namespace std;

int N, K;
deque<int> dq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	cout << "<";

	int cnt = 1;

	while (!dq.empty()) {
		int tmp = dq.front();
		dq.pop_front();

		if (cnt == K) {
			if (dq.size() == 0) {
				cout << tmp << ">";
			}
			else {
				cout << tmp << ", ";
			}
			cnt = 1;
		}
		else {
			dq.push_back(tmp);
			cnt++;
		}
	}
}
