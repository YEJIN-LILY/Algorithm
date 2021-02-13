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

ll v,e,k;
#define INF 1e18
ll dist[20001];
vector<pair<ll,ll>> vt[20001]; // i번째와 연결된 점: first, 정점간의 거리: second

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>v>>e>>k;
	
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq; //현재 위치까지의 거리, 현재 위치

	
	for(ll i=0;i<20001;i++) //초기화
		dist[i]=INF;
	dist[k]=0;
	pq.push({0,k});
	
	for(ll i=1;i<=e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		vt[a].push_back({b,c});
	}
	
	while(pq.size()){
		pair<ll,ll> cur=pq.top(); //가장 작은 거리 갖고 있는 정점
		pq.pop();
		if(dist[cur.second]<cur.first) //갱신 필요 없음
			continue;
		for(auto next:vt[cur.second]){ //현재 정점과 연결되어 있는 정점들과의 거리 갱신
			if(dist[next.first]>cur.first+next.second){ //dist > 지금까지 온 거리+다음 정점까지의 거리->갱신 필요
				dist[next.first]=cur.first+next.second;
				pq.push({dist[next.first],next.first});
			}
		}
	}
	
	for(ll i=1;i<=v;i++){
		if(dist[i]==INF)
			cout<<"INF"<<"\n";
		else
			cout<<dist[i]<<"\n";
	}
}
