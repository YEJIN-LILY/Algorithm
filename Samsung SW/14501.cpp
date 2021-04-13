#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[16][16];
int answer=0;
int dp[16];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	for(int i=1;i<=N;i++){
		cin>>arr[i][0]>>arr[i][1];
		dp[i]=arr[i][1];
	}

  //dp[i]=max(j일까지의 최댓값+i일의 금액,i일까지의 이익)
  /*
  dp[i]값도 고려하여 최댓값을 고려하는 이유는 기존에 있던 dp[i]의 값이 클 수도 있기 때문이다
  */
  
	for(int i=2;i<=N;i++){ //기준일
		for(int j=1;j<=i-1;j++){ // 1일~i-1일까지
			if(arr[j][0]<=i-j){
				dp[i]=max(arr[i][1]+dp[j],dp[i]);
			}
		}
	}
	
	for(int i=1;i<=N;i++){
		if(i+arr[i][0]-1<=N) //마지막 일수 초과하지 않아야 한다!!!
			answer=max(dp[i],answer);
	}
	cout<<answer;
}
