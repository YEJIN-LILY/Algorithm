#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool visited[26] = { false, };
int n, k;
int ans;
vector<string> v;

void init() {
	for (int i = 0; i < 26; i++) {
		visited[i] = false;
	}

	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
}

int check_word() {
	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		bool flag = true;
		string s = v[i];
		for (int j = 0; j < s.length(); j++) {
			if (visited[s[j]-'a'] == false) { //'a'를 빼주지 않아서 해맸다
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}

	return cnt;
}

void dfs(int word,int cnt) {
	if (cnt == k) {
		int tmp = check_word();
		ans = max(ans, tmp);
		return;
	}
	for (int i = word; i < 26; i++) {
		if (i == 0 || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a')
			continue;
		visited[i] = true;
		dfs(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}
	init();

	dfs(0, 5);
	cout<<ans;
}
