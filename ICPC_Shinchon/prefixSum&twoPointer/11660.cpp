#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 100000

ll N,M;
ll mat[1025][1025];
ll answer[100000];
ll preSum[1025][1025];

ll getSum(ll x1,ll y1,ll x2,ll y2){
	return preSum[x2][y2]-preSum[x1-1][y2]-preSum[x2][y1-1]+preSum[x1-1][y1-1];
}

void initializeSum(){
	for(ll i=0;i<=N;i++)
		preSum[i][0]=0;
	
	for(ll i=0;i<=N;i++)
		preSum[0][i]=0;
	
	for(ll i=1;i<=N;i++){
		for(ll j=1;j<=N;j++)
			preSum[i][j]=preSum[i-1][j]+preSum[i][j-1]-preSum[i-1][j-1]+mat[i][j];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M;
	
	for(ll i=1;i<=N;i++){
		for(ll j=1;j<=N;j++)
			cin>>mat[i][j];
	}
	
	initializeSum();
	
	for(ll i=0;i<M;i++){
		ll x1,x2,y1,y2;
		
		cin>>x1>>y1>>x2>>y2;
		answer[i]=getSum(x1,y1,x2,y2);
	}
	
	for(ll i=0;i<M;i++)
		cout<<answer[i]<<"\n";
}
