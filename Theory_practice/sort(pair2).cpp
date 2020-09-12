#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, pair<int, int>>a, pair<string, pair<int, int>>b) { //정렬기준
	if (a.second.first == b.second.first)
		return a.second.second > b.second.second;
	else
		return a.second.first > b.second.first;
}

int main() {
	vector<pair<string, pair<int, int>>>v; //이중pair
	v.push_back(pair<string, pair<int, int>>("Lily", pair<int, int>(90, 19981007)));
	v.push_back(pair<string, pair<int, int>>("Eric", pair<int, int>(97, 19971007)));
	v.push_back(pair<string, pair<int, int>>("Jessica", pair<int, int>(95, 19961007)));
	v.push_back(pair<string, pair<int, int>>("Antonio", pair<int, int>(90, 19951007)));
	v.push_back(pair<string, pair<int, int>>("Silvia", pair<int, int>(88, 19941007)));	

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';
}
