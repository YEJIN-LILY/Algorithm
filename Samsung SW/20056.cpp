#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,M,K;
int r,c,m,s,d;

int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

struct Item{
	int m;
	int s;
	int d;
};

//배열을 더 사용하지 않고 걍 아이템 구조를 만들면 된다
vector<Item> board[60][60]; 

//이동하고 나눠야 한다. 즉, 이동하고 더해야 한다!
void divide_fireball(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(board[i][j].size()>=2){
				int M=0;
				int S=0;
				
				//구슬 꺼내고 나서도 계속 true이면 모두 홀수 or 모두 짝수가 됨
				bool is_odd=true; 
				bool is_even=true;
				
				for(int k=0;k<board[i][j].size();k++){
					M+=board[i][j][k].m;
					S+=board[i][j][k].s;
					
					if(board[i][j][k].d%2==0){
						is_odd=false;
					}else
						is_even=false;
				}
				
				if(M/5==0){
					board[i][j].clear(); //소멸
				}
				else{
					int new_m=M/5;
					int new_v=S/board[i][j].size();
				
					board[i][j].clear(); //소멸
					Item tmp;
					
					if(is_odd||is_even){ //모두 짝수 or 홀수
						tmp={new_m,new_v,0};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,2};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,4};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,6};
						board[i][j].push_back(tmp);
					}else{
						tmp={new_m,new_v,1};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,3};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,5};
						board[i][j].push_back(tmp);
						tmp={new_m,new_v,7};
						board[i][j].push_back(tmp);
					} //구슬 쪼개고 끝나는 것임->이동x
				}
			}
		}
	}
}

void move(){
	vector<Item> tmp[N+1][N+1]; //먼저 이동을 '모두' 해야하므로 새로운 보드를 하나 만들자
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=0;k<board[i][j].size();k++){
				int new_x=(i+dx[board[i][j][k].d]*board[i][j][k].s); //이동할 좌표
				int new_y=(j+dy[board[i][j][k].d]*board[i][j][k].s);
			
				if(new_x>N) //이 때 좌표를 1-N으로 설정했기 때문에 %(N+1)로 했을 경우 인덱스가 0인 상황이 발생한다. 이건 따로 처리해줘야함
					new_x%=N;
				if(new_x<1)
					new_x=N-abs(new_x)%N;
				if(new_y>N)
					new_y%=N;
				if(new_y<1)
					new_y=N-abs(new_y)%N;
				
				tmp[new_x][new_y].push_back(board[i][j][k]);
			}
			board[i][j].clear(); //이동했음->해당 칸 비워줌
		}
	} //이동 완료
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){ //tmp->board 옮김
			board[i][j]=tmp[i][j];
		}
	}
	divide_fireball();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>M>>K;
	
	for(int i=0;i<M;i++){
		cin>>r>>c>>m>>s>>d;
		
		Item tmp={m,s,d}; //구슬
		board[r][c].push_back(tmp);
	}
	
	for(int i=0;i<K;i++){
		move();
	} 
	
	int sum=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=0;k<board[i][j].size();k++){
				sum+=board[i][j][k].m;
			}
		}
	}
	
	cout<<sum;
}
