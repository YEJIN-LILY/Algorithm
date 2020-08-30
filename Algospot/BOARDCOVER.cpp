#include <iostream>
#include <vector>
using namespace std;

/*
1. 타일이 덮이는 순서는 상관없다->내가 임의로 정할것임->좌상단부터 채우기로 한다: for문을 돌면서 가장 먼저 찾는 0을 덮을것임
2. 재귀호출을 하며 완전탐색하는 함수: cover/ 타일이 덮일 것인지 확인하는 함수: set->입력받은 배열을 타일 덮고 제거하는 역할도 함
3. cover: 기저사례: 모든 값이 1일 때->base로 x=y=-1로 두고 for문을 돈 뒤에도 y=-1이라면 cnt++ 하고 return한다.
4. 만약 타일이 덮일 수 있다면(set) 재귀호출한다. 그 후 타일을 제거한다.->for문(타일 종류 개수만큼)
5. set: 타일 종류 입력받을 것임
6. for문을 돈다(3만큼): 이 때 타일이 덮이는 위치가 보드판을 넘어가면 false, 이미 타일이 덮여있는 경우 false
7. 그 외 true 리턴
8. 이미 타일이 덮여있는 경우: boardGame+delta를 한 값이 1을 넘으면 이미 타일이 덮여있다는 소리이다. 이 때 바로 false를 리턴하는 것이 아니라 3만큼의 for문을 다 돈 뒤에
false를 리턴해야 한다. 그렇지 않을 경우 타일이 한 칸만 덮이고 끝나게 된다. 어차피 cover에서 타일 제거해 줄 것이다.
*/

int H,W;
int cnt;

int coverType[4][3][2]={{{0,0},{1,0},{0,1}},
						{{0,0},{0,1},{1,1}},
						{{0,0},{1,0},{1,1}},
						{{0,0},{1,0},{1,-1}}};

//type: 타일 타입(coverType중 1개)
bool set(int blockGame[20][20],int y,int x,int type,int delta){ //delta: 타일 덮을것인지에 대한 유무->1: 덮음 -1: 타일 제거
	bool flag=true;
	
	//타일 추가or제거 과정
	for(int i=0;i<3;i++){
		const int dx=x+coverType[type][i][1];
		const int dy=y+coverType[type][i][0];
		
		if(dx<0||dx>=W||dy<0||dy>=H) //영역 넘어갈 경우
			flag=false;
		else if((blockGame[dy][dx]+=delta)>1) //이미 타일이 덮여있는데 다시 덮을 경우: 이 때 바로 return하지 않는다->다른 영역도 덮은 다음 제거해야 하기 때문
			flag=false;
	}

	return flag;
}

void cover(int blockGame[20][20]){ //재귀호출을 하며 경우의 수 찾는다
	int x=-1;
	int y=-1;
	

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(blockGame[i][j]==0){
				y=i;
				x=j;
				break; //j for문 빠져나옴
			}
		}
		if(y!=-1)
				break; //i for문 빠져나옴: 해당 구문의 위치를 j for문 안에 써서 오류났다..
	}
	
	if(y==-1){ //모두 1인 상태->타일이 덮여있다->cnt증가하고 return(기저사례)
		cnt++;
		return;
	}
	
	
	for(int i=0;i<4;i++){ //타일 종류 4가지->다 돌려보면서 가능한지 찾는다
		if(set(blockGame,y,x,i,1)){//가능하다면 타일 덮고 재귀호출
			cover(blockGame);
		}
		set(blockGame,y,x,i,-1); //타일 제거
	}
}

int main(){
	int C;
	vector<int> answer;
	
	scanf("%d",&C);
	
	for(int i=0;i<C;i++){
		scanf("%d %d",&H,&W);
		
		int blockGame[20][20]={0,}; //1: 타일 있음 0: 타일 없음
		
		for(int j=0;j<H;j++){
			char str[20];
			scanf("%s",str);
			
			for(int k=0;k<W;k++){				
				blockGame[j][k]=(str[k]=='#')?1:0;
			}
		}
		
		cover(blockGame);
		answer.push_back(cnt);
		cnt=0;
	}
	
	for(int i=0;i<answer.size();i++)
		printf("%d\n",answer[i]);
}
