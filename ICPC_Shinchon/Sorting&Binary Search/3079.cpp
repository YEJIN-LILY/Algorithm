#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 100000

ll N,M,high,low,answer,mid;
ll line[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M;
	
	for(ll i=0;i<N;i++)
		cin>>line[i];
	
	high=1e18;
	low=1;
	
	while(high>=low){
		mid=(high+low)/2;
		
		ll sum=0;
		for(ll i=0;i<N;i++){
			sum+=mid/line[i]; //mid초만큼 걸릴 때 처리할 수 있는 인원수
			
			if(sum>=M)
				break;
		}
		
		if(sum>=M){
			answer=mid;
			high=mid-1;
		}else
			low=mid+1;
	}
	
	cout<<answer<<"\n";
}
