#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MAX 100000

ll snack[1000000];
ll N,M,high,low,mid,answer;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>M>>N;
	
	for(ll i=0;i<N;i++)
		cin>>snack[i];
	
	high=1e9;
	low=1;
	
	while(high>=low){
		mid=(high+low)/2;
		
		ll sum=0;
		
		for(ll i=0;i<N;i++){
			sum+=snack[i]/mid; //mid 길이만큼 나눠준다고 했을 때의 인원수
			
			if(sum>=M)
				break;
		}
		
		if(sum>=M){
			answer=mid;
			low=mid+1;
		}else
			high=mid-1;
	}
	
	cout<<answer<<"\n";
}
