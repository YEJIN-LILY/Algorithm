#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll n,k;
ll answer;
ll cnt;
queue<pair<ll,ll>> q;
bool visited[100001];

void bfs(){
	q.push({n,0});
	
	while(!q.empty()){
		pair<ll,ll> now=q.front();
		q.pop();

		if(now.first==k){
			cout<<now.second;
			return;
		}else if(now.first<0)
			continue;
		else if(now.first>100000)
			continue;
		else if(visited[now.first])
			continue;
		else{
			visited[now.first]=true;
			q.push({now.first-1,now.second+1});
			q.push({now.first*2,now.second+1});
			q.push({now.first+1,now.second+1});	
		}
		
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>k;
	
	for(int i=0;i<=100000;i++)
		visited[i]=false;
	
	bfs();
}
