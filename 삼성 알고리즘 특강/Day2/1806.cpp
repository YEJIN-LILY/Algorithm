#include <iostream>
using namespace std;

long long N, M;
int A[100001];
long long ans=987654321;
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
	bool flag = false;

	sum = A[0];

	while (true) {
		if (sum >= M&&start<=end) { //순서 뒤바뀌지 않을 때까지만
			flag = true;
			ans=min(ans,end-start+1);
			//cout << "ans: " << ans << endl;
			sum -= A[start++];
		}
		else {
			if (end == N - 1)
				break;
			else
				sum += A[++end];
		}
	}
	
	if (flag)
		cout << ans;
	else
		cout << 0;
}
