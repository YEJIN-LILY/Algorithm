#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M;
vector<int> tree;
long long ans;
long long sum;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >>tmp;

		tree.push_back(tmp);
	}

	sort(tree.begin(), tree.end());

	long long start = 0;
	long long end =tree[tree.size()-1];
	long long avg = (start + end) / 2;

	while (true) {
		long long rest = 0;
		avg = (start + end) / 2;

		for (int i = 0; i < tree.size(); i++) {
			if (tree[i] > avg)
				rest += (tree[i] - avg);
		}

		if (rest == M) { //정확히 M을 얻어갈 수 있음
			ans = max(avg, ans);
			break;
		}
		else if(rest<M){
			end = avg - 1;
		}
		else { //M 이상을 가져갈 때
			start = avg + 1;
			ans = avg; //이것 또한 정답이 될 수 있음!!!주의
		}

		if (start > end) //순서가 뒤바뀌면 더이상 해당되눈 경우 없음->반복문 빠져나온다
			break;
	}

	cout << ans;
}
