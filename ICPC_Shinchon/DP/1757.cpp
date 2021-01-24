#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define ll long long
using namespace std;

ll n,m,arr[10001];
ll dp[10005][505][2]; //dp[x][y][z]: x초에 y만큼의 지침지수를 가지고 달리는지의 여부(z)

void solution(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j==1){ //지침지수 1일 때
				dp[i][j][0]=max(dp[i-1][j+1][1],dp[i-1][j+1][0]); 
				dp[i][j][1]=max(dp[i-1][j-1][1],dp[i-1][j-1][0])+arr[i];
			}
			else if(j==0){ //지침지수 0일 때->지침지수가 0이면서 달리고 있을 수는 없음
				dp[i][j][0]=max({dp[i-1][j+1][0],dp[i-1][j+1][1],dp[i-1][j][0]}); //지침지수가 0이면서 이전에 쉬고 있는 상황도 고려해야 함!->dp[i-1][j][0]: j불변
			}else{ //지침지수가 0,1,이 아닐 때
				dp[i][j][0]=max(dp[i-1][j+1][0],dp[i-1][j+1][1]);
				dp[i][j][1]=dp[i-1][j-1][1]+arr[i]; //쉬다가 달리는데 지침지수가 1이 아닐 수 없음->이전에 계속 달리고 있어야 함
			}
		}
	}
	
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	
	solution();
	
	cout<<dp[n][0][0]; //n초에 달린 최대 거리 출력. 지침지수는 반드시 0이 되어야 
}
