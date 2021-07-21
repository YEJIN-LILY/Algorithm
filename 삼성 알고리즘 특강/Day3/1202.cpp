#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
	가방 무게순으로 오름차순 정렬
	보석 무게순으로 오름차순 정렬
	=>이후에 for문을 돌면서 bags[i]에 들어갈 수 있는 보석을 pq에 넣을 것임
	이 때 pq는 보석 가격순으로 정렬된다
*/

long long N, K;
long long M, V, C,ans;

vector<pair<long long, long long>> jewelry;
vector<long long> bag;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> M >> V;

		jewelry.push_back({ M,V });
	}

	sort(jewelry.begin(), jewelry.end());


	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.push_back(C);
	}

	sort(bag.begin(), bag.end());
	int jIndex = 0;
	
	priority_queue<long long, vector<long long>> pq; //for문 안에서 선언하면 안된다. 가방을 이동하면서 볼 때 무게가 점점 커진다->이전에 담을 수 있었지만 담지 못했던
  //보석도 넣을 수 있다는 뜻! 이전의 가방에서 담을 수 있었던 보석도 유지되어야 한다.
	for (int i = 0; i < bag.size(); i++) {
		long long bag_weight = bag[i];
		
		while (jIndex < jewelry.size() && jewelry[jIndex].first <= bag_weight) {
			pq.push(jewelry[jIndex].second);
			jIndex++;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop(); //pop 해주어야 한다!!!그렇지 않으면 계속 값이 남아있음..
		}
	}
	cout << ans;
}
