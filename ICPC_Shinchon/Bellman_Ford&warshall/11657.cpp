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
#define INF 1e18

ll n,m,a,b,c;
ll dist[600];
vector<pair<ll,ll>> adj[7000]; //방향성 있음
bool negative_cycle=false;

void solution(){	
	for(int i=1;i<=n;i++){ //v번 반복
		for(int from=1;from<=n;from++){ //모든 정점에 대해서
			if(dist[from]==INF)
				continue;
			for(int a=0;a<adj[from].size();a++){ //연결되어 있는 간선 살펴봄
				ll to=adj[from][a].first;
				ll cost=adj[from][a].second;
				
				if(dist[to]>dist[from]+cost){
					if(i==n){
						negative_cycle=true;
						return;
					}
					dist[to]=dist[from]+cost;
				}
			}
		}
	}
}

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		adj[a].push_back({b,c});
	}
	
	for(int i=0;i<600;i++){
		dist[i]=INF;
	}
	
	dist[0]=0;
	dist[1]=0;
	
	solution();
	
	if(negative_cycle){
		cout<<"-1";
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(dist[i]==INF)
			cout<<"-1\n";
		else
			cout<<dist[i]<<"\n";
	}
}
