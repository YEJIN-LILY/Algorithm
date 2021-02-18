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

ll tc,n,m,w,s,e,t;


int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>tc;
	
	
	while(tc--){
		ll dist[600];
		vector<pair<ll,ll>> adj[7000]; //방향성 있음
		bool negative_cycle=false;
		
		for(int i=0;i<600;i++){
			dist[i]=INF;
		}

		
		cin>>n>>m>>w; //간선의 개수: m+w. m: 양방향 간선. w: 단방향 간선. 음수 존재
		
		for(int j=0;j<m;j++){ //도로정보
			cin>>s>>e>>t;

			adj[s].push_back({e,t});
			adj[e].push_back({s,t});
		}
		
		for(int k=0;k<w;k++){ //웜홀정보
			cin>>s>>e>>t;
			adj[s].push_back({e,t*(-1)});
		}
		
		for(int i=1;i<=n;i++){ //v번 반복
			for(int from=1;from<=n;from++){ //모든 정점에 대해서
				
				for(int a=0;a<adj[from].size();a++){ //연결되어 있는 간선 살펴봄
					ll to=adj[from][a].first;
					ll cost=adj[from][a].second;
				
					if(dist[to]>dist[from]+cost){
						if(i==n){
							negative_cycle=true;
						}
						dist[to]=dist[from]+cost;
					}
				}
			}
		}
		
		negative_cycle?cout<<"YES\n":cout<<"NO\n";
	}

}
