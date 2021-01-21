#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	int sum, tmp,i;
	for (i = 1; i < n; i++) { //생성자 찾기. 생성자는 무조건 n보다는 작다
		sum = i;
		tmp = i;

		while (tmp) {
			sum += (tmp % 10);
			tmp /= 10;
		}

		if (sum == n) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
}
