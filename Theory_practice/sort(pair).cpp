#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector < pair<int, string> > v;
	v.push_back(pair<int, string>(90, "조권"));
	v.push_back(pair<int, string>(85, "리정혁"));
	v.push_back(pair<int, string>(82, "윤세리"));
	v.push_back(pair<int, string>(98, "현빈"));
	v.push_back(pair<int, string>(79, "손예진"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << ' '; //이름출력
	}
}
