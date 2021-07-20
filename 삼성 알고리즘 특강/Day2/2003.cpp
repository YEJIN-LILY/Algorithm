#include <iostream>
using namespace std;

long long N, M;
int A[10001];
long long ans;
long long sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long long start = 0;
	long long end = 0;

	sum = A[0];

	while (true) {
		if (sum == M) {
			ans++;
			sum -= A[start++];
		}
		else if (sum > M) {
			sum -= A[start++];
		}
		else {
			if (end == N - 1) //sum이 M보다 작은데(end가 뒤로 가야 하는 상황) end가 마지막까지 이미 도달해있음->더 이상의 경우의 수는 없다
				break;
			else
				sum += A[++end];
		}
	}
	cout << ans;
}
