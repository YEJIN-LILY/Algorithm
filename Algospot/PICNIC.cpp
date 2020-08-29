#include <iostream>
#include <vector>
using namespace std;

/*
1. 짝이 될 수 있는 쌍을 표시한 2차원 배열 areFriends와 짝이 맺어졌음을 의미하는 1차원 배열 finished 생성
2. 값들을 입력받는다. 이 때 areFriends배열은 대칭적
3. 먼저 번호가 작은 학생들의 짝 먼저 찾아나간다->for문을 통해 finished 배열 확인
4. 3에서 정한 학생번호의 다음 순서부터 짝이 될 수 있는지 확인한다(finished가 false이고 areFriends가 true이면 됨)
5. 찾은 쌍을 fix하고 다음 순서쌍을 찾는 경우와 찾은 쌍을 세지 않고 다음으로 넘기는 두 가지의 경우가 있음(백준 알고리즘에서 부분수열의 합과 비슷: 1182)
6. finished배열의 값들을 true로 하고 재귀호출 그 다음 false로 다시 바꿔줌: 어차피 for문으로 계속 돌 것이기 때문에 재귀호출 필요없음
*/
int n;
int cnt;
vector<int> answer;

void check_mate(bool areFriends[10][10],bool finished[10]){
	int firstFree=-1; //첫 번째로 확인할 학생의 번호
	
	for(int i=0;i<n;i++){ //첫 번째로 매칭시킬 학생의 번호 찾음
		if(finished[i]==false){
			firstFree=i;
			break; //break해주지 않아 에러났다
		}
	}
	
	if(firstFree==-1){ //그대로 -1이라면 모든 짝들을 다 찾았음을 의미
		cnt++;
		return;
	}
		
	
	for(int pairWith=firstFree+1;pairWith<n;pairWith++){ //한 명 fix하고 fix한 한 명의 짝을 찾는 과정
		if(finished[pairWith]==false&&areFriends[firstFree][pairWith]){
			finished[pairWith]=finished[firstFree]=true; //짝 맺음
			check_mate(areFriends,finished); //재귀호출(나머지 학생들의 짝을 찾도록)
			finished[pairWith]=finished[firstFree]=false; //해당 짝을 선택하지 않고 넘어감
		}
	}
}

int main(){
	int C,m;
	scanf("%d",&C);
	
	for(int i=0;i<C;i++){
		scanf("%d %d",&n,&m);
		
		bool areFriends[10][10]={false,};
		bool finished[10]={false,};
		cnt=0;
		
		for(int j=0;j<m;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			areFriends[a][b]=true; //대칭적
			areFriends[b][a]=true;
		}
		
		check_mate(areFriends,finished);
		answer.push_back(cnt);
	}
	
	for(int i=0;i<answer.size();i++){
		printf("%d\n",answer[i]);
	}
}
