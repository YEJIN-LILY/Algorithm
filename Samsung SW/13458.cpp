#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll N,B,C,cnt,rest;
bool flag=true;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	vector<ll> v(N);
	
	for(ll i=0;i<N;i++){
		cin>>v[i];
	}
	cin>>B>>C;
	
	for(ll i=0;i<N;i++){
		rest=v[i];
		flag=true;
		
		while(rest>0){
			if(rest<=B&&flag){ //총감독만 있으면 됨
				cnt++;
				flag=false;
				break;
			}else if(rest>B&&flag){
				cnt++;
				rest-=B;
				flag=false;
			}
			if(rest<C){
				cnt++;
				break;
			}else{
				cnt+=(rest/C);
				rest=rest%C;
				if(rest)
					cnt++;
				break;
				
			}
		}
	}
	
	cout<<cnt;
}
