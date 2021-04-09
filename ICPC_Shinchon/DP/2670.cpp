#include <iostream>
#include <algorithm>
using namespace std;

int N;
double dp[10001];
double answer;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> N;

	dp[0]=0;
	
	for(int i=1;i<=N;i++){
		cin>>dp[i];
		
		dp[i]=max(dp[i],dp[i]*dp[i-1]); //값이 들어올 때마다 갱신
		
		answer=max(dp[i],answer); //어차피 여기서 최댓값 출력할 것임: 1.3/0.9/1.4/0.9/1.4 고려x
	}
	
	cout<<fixed;
	cout.precision(3);
	cout<<answer;
}
