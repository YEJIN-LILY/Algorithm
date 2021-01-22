#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;
long long dp[1000001];



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin>>n;
	
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	
	for(int i=5;i<=1000000;i++){
		if(i%3==0&&i%2!=0){
			dp[i]=min(dp[i/3],dp[i-1])+1;
		}else if(i%3!=0&&i%2==0)
			dp[i]=min(dp[i/2],dp[i-1])+1;
		else if(i%3==0&&i%2==0)
			dp[i]=min({dp[i/2],dp[i-1],dp[i/3]})+1;
		else
			dp[i]=dp[i-1]+1;
	}
	
	cout<<dp[n];
}
