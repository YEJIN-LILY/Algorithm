#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
long long dp[101];

void solution(int n){
	for(int i=11;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-5];
	}
	
	cout<<dp[n]<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>T;
	
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	dp[6]=3;
	dp[7]=4;
	dp[8]=5;
	dp[9]=7;
	dp[10]=9;
	
	for(int i=0;i<T;i++){
		int k;
		cin>>k;
		
		solution(k);
	}
}
