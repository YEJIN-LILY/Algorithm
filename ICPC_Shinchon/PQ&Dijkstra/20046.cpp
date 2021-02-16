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

ll row,col;


ll dy[]={1,0,-1,0};
ll dx[]={0,1,0,-1};

struct Node{
	ll weight,n_row,n_col;
};

struct cmpNode{
	bool operator()(Node x,Node y){
		return x.weight>=y.weight;
	}
};

int main(int argc, const char * argv[]){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>row>>col;
	ll road[row][col];
	ll dist[1001][1001];
	priority_queue<Node,vector<Node>,cmpNode> pq;
	
	
	for(ll i=0;i<row;i++){
		for(ll j=0;j<col;j++){
			cin>>road[i][j];
			dist[i][j]=INF;
		}
	}

	if(road[0][0]==-1||road[row-1][col-1]==-1){
		cout<<"-1";
		return 0;
	}
	
	struct Node cur;
	struct Node new_node;
	
	
	
	//시작점
	dist[0][0]=road[0][0];
	cur.weight=dist[0][0];
	cur.n_row=0;
	cur.n_col=0;
	pq.push(cur);

	
	
	
	while(pq.size()){
		cur=pq.top();
		pq.pop();
		
		if(cur.n_row==row-1&&cur.n_col==col-1)
			break;

		
		for(ll i=0;i<4;i++){

			ll y=cur.n_row+dy[i];
			ll x=cur.n_col+dx[i];
			
			if(y<row&&y>=0&&x<col&&x>=0&&dist[y][x]<=cur.weight+road[y][x]||cur.weight==-1) //인덱스 체크 주의!!!제발...
				continue;
			
			if(y<row&&y>=0&&x<col&&x>=0&&road[y][x]!=-1&&dist[y][x]>cur.weight+road[y][x]){

				dist[y][x]=cur.weight+road[y][x];
				new_node.weight=dist[y][x];
				new_node.n_row=y;
				new_node.n_col=x;
				pq.push(new_node);
			}
		}
	}

	if(dist[row-1][col-1]==INF){
		cout<<"-1";
		return 0;
	}
	cout<<dist[row-1][col-1]; 
	return 0;
}
