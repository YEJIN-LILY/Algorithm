#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N,M,gas;
int r,c;
int board[25][25];


int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

//승객 정보
struct Person{
	int start_x;
	int start_y;
	int destination_x;
	int destination_y;
}customer[450];

struct State{ //현재 
	int x,y,gas; //남아있는 가스의 양: 이 양이 큰 것이 최단거리임
};

/*
priority_queue는 두 번째 인자 기준으로 정렬한다.
이 때 '남아있는' 가스의 양이 큰 것이 최단거리다!!!
*/

//이외의 것들은 return false를 하도록 처리해주자...여기서 시간 많이 뺏겼다ㅠㅠ
bool operator <(State a,State b){
	if(a.gas<b.gas)
			return true;
	if(a.gas==b.gas){
		if(a.x>b.x)
			return true;
		if(a.x==b.x)
			if(a.y>b.y)
				return true;
	}
	return false;
}

//승객 데려다줌
bool getCustomer(int start_x,int start_y,int ppl){
	bool visited_destination[25][25]={false,}; //그 때마다 visited배열이 새로 만들어져야한다!!!!!
	
	queue<pair<State,int>> pq; //현재 택시 상태, 이동거리
	visited_destination[start_x][start_y]=true;
	
	pq.push({{start_x,start_y,gas},0});
	
	while(!pq.empty()){
		int cur_x=pq.front().first.x;
		int cur_y=pq.front().first.y;
		int cur_gas=pq.front().first.gas;
		int dist=pq.front().second;
		pq.pop();
		
		if(cur_gas<0){ //가는 도중 연료 소진
			return false;
		}
		//도착지 도달
		if(cur_x==customer[ppl].destination_x&&cur_y==customer[ppl].destination_y){
			gas=cur_gas+dist*2;
			r=cur_x; //현재위치 갱신
			c=cur_y;
			return true;
		}
		
		for(int i=0;i<4;i++){ //상하좌우 탐색
			int newX=cur_x+dx[i];
			int newY=cur_y+dy[i];
			
			if(newX<=0||newY<=0||newX>N||newY>N)
				continue;
			if(visited_destination[newX][newY]==true||board[newX][newY]==-1)
				continue;
			
			visited_destination[newX][newY]=true; //방문했다고 표시해주기!!
			pq.push({{newX,newY,cur_gas-1},dist+1});
		}
	}
	
	return false; //도착지 도달하지 못하고 while문 빠져나왔다? 도착지 못감
}

int find_customer(int taxi_x,int taxi_y){ //승객 찾기
	bool visited_customer[25][25]={false,};
	visited_customer[taxi_x][taxi_y]=true;
	
	priority_queue<State> pq; //현재위치에서의 상태: 먼저 태울 조건들이 있다. 우선순위 큐로 구현하자. 이 때 연산자<를 오버로딩하면 됨
	pq.push({taxi_x,taxi_y,gas});
	
	bool is_find=false; //승객한테 갈 수 없을수도 있음

	int x,y,ppl; //승객 태우고 갈 때 전달할 값들
	
	while(!pq.empty()){
		//우선순위 큐->front가 아니라 top
		int cur_x=pq.top().x; //현재위치
		int cur_y=pq.top().y;
		int curGas=pq.top().gas;
		pq.pop();
		
		if(curGas==-1){
			break;
		}

		if(board[cur_x][cur_y]>0){ //승객이 있는 곳에 도착함
			is_find=true;
			x=cur_x;
			y=cur_y;
			gas=curGas;
			ppl=board[cur_x][cur_y];
			board[cur_x][cur_y]=0; //승객 태웠으니 보드에서 
			break;
		}
		
		for(int i=0;i<4;i++){
			int newX=cur_x+dx[i];
			int newY=cur_y+dy[i];
			
			if(newX<=0||newY<=0||newX>N||newY>N){
				continue;
			}
			if(visited_customer[newX][newY]||board[newX][newY]==-1)//이미 방문한 곳이거나 벽이 있는 곳이면 갈 수 없음
				continue;
			
			visited_customer[newX][newY]=true;
			pq.push({newX,newY,curGas-1}); //한 칸씩만 이동할 수 있다
		}
	}
	
	if(is_find==false){ //승객한테 갈 수 없음
		return -1;
	}
	if(getCustomer(x,y,ppl)){
		return gas;
	}else
		return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>M>>gas;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>board[i][j];
			if(board[i][j]==1)
				board[i][j]=-1; //벽 표현 바꿈
		}
	}
	
	cin>>r>>c;
	
	for(int i=1;i<=M;i++){
		cin>>customer[i].start_x>>customer[i].start_y>>customer[i].destination_x>>customer[i].destination_y;
		board[customer[i].start_x][customer[i].start_y]=i; //보드에 승객 위치 기록
	}
	
	for(int i=0;i<M;i++){
		int n=find_customer(r,c);

		if(n==-1){
			cout<<-1;
			return 0;
		}
		if(i==M-1)
			cout<<gas;
	}
}
