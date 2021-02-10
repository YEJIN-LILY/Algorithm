#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll a,b;
ll answer;
ll cnt;
queue<pair<ll,ll>> q;

void bfs(){
	q.push({a,1});
	
	while(!q.empty()){
		pair<ll,ll> k=q.front();
		q.pop();
		if(k.first>b)
			continue;
		else if(k.first==b){
			cout<<k.second;
			return;
		}
		q.push({k.first*2,k.second+1});
		q.push({k.first*10+1,k.second+1});
	}
	
	cout<<"-1";
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>a>>b;
	
	
	bfs();
}
