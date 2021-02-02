#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll N,M,cnt,sum;
ll A[10000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M;
	
	for(ll i=0;i<N;i++)
		cin>>A[i];
	
	ll start=0;
	ll end=1;
	sum=A[0];
	cnt=0;
	
	while(start<N){
		if(sum==M){
			cnt++;
			sum-=A[start];
			start++;
		}
		
		if(end==N&&sum<M)
			break;
		else if(sum>M){
			sum-=A[start];
			start++;
		}
		else{
			sum+=A[end];
			end++;
		}
			
		
	}
	
	cout<<cnt;
}
