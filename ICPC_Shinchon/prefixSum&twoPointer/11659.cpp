#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 100000

ll N,M;
ll nums[100001];
ll answers[100001];
ll sum[100001];

ll prefixSum(ll i,ll j){
	return sum[j]-sum[i-1];
}

void initializeSum(){
	sum[0]=0;
	
	for(ll i=1;i<=N;i++)
		sum[i]=sum[i-1]+nums[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M;
	
	for(ll i=1;i<=N;i++){
		cin>>nums[i];
	}
	
	initializeSum();
	
	for(ll i=0;i<M;i++){
		ll a,b;
		cin>>a>>b;
		
		answers[i]=prefixSum(a,b);
	}
	
	for(ll i=0;i<M;i++)
		cout<<answers[i]<<"\n";
}
