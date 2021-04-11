#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int stair;
int dp[301][3]; //현재 계단 기준 0: 안밟음. 1: 첫번째로 밟음(연속 끊어지고 새로 시작). 2: 2번 연속으로 밟음 

/*
0번, 1번, 2번 연속으로 밟는지 유뮤 체크하면 i-2번째에서 오는 경우 고려할 필요 없음
i-1번째의 최댓값에 이미 
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>stair;
	
	vector<int> v(stair+1);
	
	for(int i=1;i<=stair;i++){
		cin>>v[i];
	}
	
	dp[1][0]=0;
	dp[1][1]=v[1];
	dp[2][0]=v[1];
	dp[2][1]=v[2];
	dp[2][2]=v[1]+v[2];
	
	for(int i=3;i<=stair;i++){
		dp[i][0]=max(dp[i-1][1],dp[i-1][2]); //현재 계단 안 밟음->이전 계단은 반드시 밟아야 함
		dp[i][1]=dp[i-1][0]+v[i]; //현재 계단 다시 처음으로 밟음->이전 계단 반드시 밟으면 안됨
		dp[i][2]=dp[i-1][1]+v[i]; //두 번 연속으로 밟음->이전 계단 반드시 밟아야 함
	}
	
	cout<<max(dp[stair][1],dp[stair][2]);
}
