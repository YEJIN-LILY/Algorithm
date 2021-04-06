#include <iostream>
using namespace std;

int N,cnt;
bool isused1[40]; //열
bool isused2[40]; // /(우상 대각선): i+j
bool isused3[40]; // \(좌상 대각선): i-j->음수인 경우 존재!!!=>i-j+N-1
void solution(int queen){ //queen: 퀸이 존재하는 행 인덱스
	if(queen==N){
		cnt++;
		return;
	}
	for(int i=0;i<N;i++){
		if(isused1[i]||isused2[i+queen]||isused3[queen-i+N-1]) //이미 퀸을 놓았으면
			continue;
		isused1[i]=true;
		isused2[i+queen]=true;
		isused3[queen-i+N-1]=true;
		solution(queen+1);
		isused1[i]=false;
		isused2[i+queen]=false;
		isused3[queen-i+N-1]=false;
	}
}

int main(){
	cin>>N;
	
	solution(0);
	cout<<cnt;
}
