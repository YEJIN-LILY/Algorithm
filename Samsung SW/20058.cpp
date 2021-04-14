#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N,Q;
int A[70][70];
int partitial,num,sum;
int dx[4]={0,0,1,-1}; //행
int dy[4]={1,-1,0,0}; //열
bool visited[70][70]={false,};


//n: 한 변의 길이: 문제에 따라서 인덱스 주의
//x축 대칭: (i,j)->(n-i-1,j)
//y축 대칭: (i,j)->(i,n-j-1)
//점대칭: (i,j)->(n-j-1,n-i-1)
//90도 회전: (i,j)->(j,n-i-1);

void rotate(int row,int col){ //작게 나눈 사각형 90도 회전
	int tmp[partitial][partitial];
	
	for(int i=row;i<row+partitial;i++){ //큰 사각형에서 나눌 사각형의 시작점부터 시작
		for(int j=col;j<col+partitial;j++){
			tmp[j-col][partitial-(i-row)-1]=A[i][j]; //주의!!!:(i,j)->(j,n-i-1)이 되는 것이다=>tmp에 저장되어야 함. 이 때 시작점이 A의 인덱스이므로 
                                               //tmp에서 col, row만큼을 빼 주어야 tmp의 원래 인덱스가 나온다
		}
	}
	
	for(int i=row;i<row+partitial;i++){ //임시배열 다시 넣어주기
		for(int j=col;j<col+partitial;j++){
			A[i][j]=tmp[i-row][j-col];
		}
	}
}

void melting(){	
	vector<pair<int,int>> v;
	
	for(int i=0;i<num;i++){ //전체 행렬 다 돌아본다
		for(int j=0;j<num;j++){
			if(A[i][j]==0) //이미 0이면 녹일 수 없음!!!
				continue;
			else{
				int is_ice=0; //현재 점 기준으로 상하좌우 탐색
				
				for(int a=0;a<4;a++){ //녹일 수 있는지 탐색
					int nx=i+dx[a];
					int ny=j+dy[a];
					
					if(nx<0||ny<0||nx>=num||ny>=num) //인덱스 넘으면 안됨
						continue;
					if(A[nx][ny]==0)
						continue;
					is_ice++;
				}
				if(is_ice<3) //주의!!!: 바로 갱신하면 안된다. 전체적으로 다 파악하고 한꺼번에 갱신한다!!!->일단 벡터에 넣어두자
					v.push_back({i,j});
			}
		}
	}
	
	for(int i=0;i<v.size();i++){ //여기서 녹인다...ㅠㅠ
		int x=v[i].first;
		int y=v[i].second;
		
		A[x][y]--;
	}
}

void solution(int l){
	partitial=pow(2,l);
	
	for(int i=0;i<num;i+=partitial){
		for(int j=0;j<num;j+=partitial){
			rotate(i,j);
		}
	}
	
	melting();
}

int getSum(){
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			sum+=A[i][j];
		}
	}
	return sum;
}

int bfs(int x,int y){ //최대 덩어리 개수->bfs로 탐색->큐 이용하자!
	visited[x][y]=true;
	
	queue<pair<int,int>> q; //좌표값을 가지고 있어야 한다
	q.push({x,y});
	
	int large=1; //최소 덩어리 크기
	
	while(!q.empty()){
		int i=q.front().first;
		int j=q.front().second;
		q.pop();
		
		for(int k=0;k<4;k++){ //현재 점 기준으로 상하좌우 탐색
			int nx=i+dx[k];
			int ny=j+dy[k];
			
			if(nx<0||ny<0||nx>=num||ny>=num)
				continue;
			else{
				if(A[nx][ny]&&!visited[nx][ny]){ //얼음이 남아있고 가보지 않은 곳이면
					large++;
					visited[nx][ny]=true;
					q.push({nx,ny});
				}
			}
		}
	}
	
	return large;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>Q;

	
	num=pow(2,N); //전체 변의 길이
	
	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			cin>>A[i][j];
		}
	}

	for(int i=0;i<Q;i++){ //쪼개는 변의 길이 입력받음
		int k;
		cin>>k;
		solution(k);
	}
	
	cout<<getSum()<<"\n";
	
	int result=0;
	
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++){
			if(A[i][j]!=0&&visited[i][j]==false){ //시작점이 0이 아니고 아직 탐색하지 않은 점이면 bfs탐색
				result=max(bfs(i,j),result); //bfs결과로 얻은 덩어리 크기랑 기존값이랑 비교해서 max값만
			}
		}
	}
	cout<<result; 

}
