#include <iostream>
#include <cstring>
using namespace std;

int map[100][100];
int n;
int visited[100][100];

int canJump(int y,int x){
	if(y==n-1&&x==n-1)
		return 1;
	if(y>=n||x>=n)
		return 0;
	
	int& ret=visited[y][x];
	
	if(ret!=-1) //방문시도했을 경우
		return ret; //true.false(도달할수 있는지의 여부)
	
	int dist=map[y][x];
	
	return ret=(canJump(y+dist,x)||canJump(y,x+dist));
}

int main(){
	int c;
	cin>>c;
	
	for(int i=0;i<c;i++){
		cin>>n;
		memset(visited,-1,sizeof(visited));
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				cin>>map[j][k];
			}
		}
		
		if(canJump(0,0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}
