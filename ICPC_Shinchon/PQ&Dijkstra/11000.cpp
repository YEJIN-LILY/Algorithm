#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
using namespace std;

#define ll long long

ll n,a,b;
vector<pair<ll,ll>> v;
priority_queue<ll,vector<ll>,greater<>> pq;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n;
	
	for(ll i=0;i<n;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	
	sort(v.begin(),v.end());
	pq.push(v[0].second);
	
	for(ll i=1;i<n;i++){

		ll cur=pq.top(); //가장 먼저 끝나는 강의의 시간
		
		if(cur>v[i].first){
			pq.push(v[i].second);
		}else{
			pq.pop();
			pq.push(v[i].second);
		}
	}
	
	cout<<pq.size();
}
