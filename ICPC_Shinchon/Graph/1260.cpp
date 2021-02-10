#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

ll N,M,V;
bool visited[1001];
int graph[1001][1001];

void bfs(int node){
	queue<int> q;
	q.push(node);
	
	visited[node]=true;
	
	while(q.size()){
		int tmp=q.front();
		cout<<tmp<<' ';
		q.pop();
		
		for(int i=1;i<=N;i++)
			if(graph[tmp][i]&&!visited[i])
				q.push(i),visited[i]=true;
	}
}

void dfs(int node){
	cout<<node<<' ';
	
	visited[node]=true;
	
	for(int i=1;i<=N;i++){
		if(graph[node][i]&&!visited[i])
			dfs(i);
	}
}

void initArr(){
	for(int i=0;i<1001;i++)
		visited[i]=false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>N>>M>>V;
	
	ll a,b;
	
	for(int i=0;i<1001;i++){
		visited[i]=false;
		for(int j=0;j<1001;j++){
			graph[i][j]=0;
			graph[j][i]=0;
		}
			
	}
	
	for(int i=0;i<M;i++){
		cin>>a>>b;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	
	dfs(V);
	initArr();
	cout<<"\n";
	bfs(V);
}
