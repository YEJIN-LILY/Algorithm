#include <iostream>
using namespace std;

int N,M;
bool isused[10]; //사용 여부
int answer[10]; //출력용

void solution(int length){
	if(length==M){ //길이 다 차면
		for(int i=0;i<M;i++){
			cout<<answer[i]<<' ';
		}
		cout<<"\n";
		return;
	}
	for(int i=1;i<=N;i++){ //수열 숫자들 선택
		if(isused[i])//이미 사용했으면 넘어감
			continue;
		isused[i]=true; //선택
		answer[length]=i;
		solution(length+1); //다음 숫자 탐색
		isused[i]=false; //선택 안 했을 경우
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>M;
	solution(0);
}
