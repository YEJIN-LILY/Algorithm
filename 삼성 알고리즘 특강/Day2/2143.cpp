#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long T, n,m;
long long A[1001];
long long B[1001];
vector<long long> sumA;
vector<long long> sumB;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> T >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}

	//A의 부배열
	for (int i = 0; i <n; i++) {
		long long sum = 0;
		for (int j = i; j < n; j++) {
			sum += A[j];
			sumA.push_back(sum);
		}
	}

  //오름차순 정렬
	sort(sumA.begin(), sumA.end());

	/*
	for (int i = 0; i < sumA.size(); i++) {
		cout << sumA[i] << ' ';
	}
	*/

	//B의 부배열
	for (int i = 0; i < m; i++) {
		long long sum = 0;
		for (int j = i; j < m; j++) {
			sum += B[j];
			sumB.push_back(sum);
		}
	}

  //내림차순 정렬
	sort(sumB.begin(), sumB.end(),greater<>());
	/*
	cout << endl;
	for (int i = 0; i < sumB.size(); i++) {
		cout << sumB[i] << ' ';
	}
	*/

	long long ans = 0;
	int ptA = 0;
	int ptB = 0;

  /*
  sum으로 계산할 경우 +-도 생각해야 하고
  같은것이 여러개 있는 것도 생각해야 한다.
  A를 고정하고 B를 움직이자
  */
	while (ptA < sumA.size() && ptB < sumB.size()) {
		long long curA = sumA[ptA];
		long long target = T-sumA[ptA];

		if (target ==sumB[ptB] ) { //숫자가 같은것이 여러개 있는지 확인해야함
			long long cntA = 0;
			long long cntB = 0;

			while (ptA < sumA.size()&& curA == sumA[ptA]) {
				cntA++;
				ptA++;
			}
			while (ptB < sumB.size()&&target==sumB[ptB]) {
				ptB++;
				cntB++;
			}
			ans += cntA * cntB;
		}
		else if (sumB[ptB] < target) { //A키우기
			ptA++;
		}
		else {//B키우기
			ptB++;
		}
	}

	cout << ans;
}
