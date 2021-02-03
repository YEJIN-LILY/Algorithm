#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll cnt,N,a,b;
vector<ll> A;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N;
	A.resize(N);
	
	for(ll i=0;i<N;i++)
		cin>>A[i];
	
	sort(A.begin(),A.end());

	
	
	for(ll i=0;i<N;i++){
		
		a=0;
		b=N-1;
		
		while(true){
			if(a==i)
				a++;
			if(b==i)
				b--;
			
			if(a>b||a==b)
				break;
		
			ll sum=A[a]+A[b];
		
			if(sum==A[i]){
				//cout<<"start: "<<a<<" end: "<<b<<"\n";
				//cout<<A[i]<<"\n";
				cnt++;
				break;
			}
			if(sum<A[i])
				a++;
			if(sum>A[i])
				b--;
		}
	}
	
	
	cout<<cnt;
	
}
