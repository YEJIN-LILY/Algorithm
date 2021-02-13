#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <iterator>
#include <functional>
using namespace std;

#define ll long long

ll n;

struct cmp{
	bool operator()(ll x,ll y){
		if(abs(x)==abs(y)){
			return x>y;
		}
		return abs(x)>abs(y);
	}
};

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n;
	
	priority_queue<ll,vector<ll>,cmp>pq;
	
	while(n--){
		ll x;
		cin>>x;
		
		if(x!=0){
			pq.push(x);
		}else{
			if(!pq.empty()){
				ll k=pq.top();
				cout<<k<<"\n";
				pq.pop();
			}else
				cout<<"0\n";
			
		}
	}
	
	
}
