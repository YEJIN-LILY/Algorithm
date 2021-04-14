#include <iostream>
#include <deque>
using namespace std;

deque<int> belt;
deque<bool> robot;
int N,K,cnt,level;

/*
회전->deque
앞, 뒤에서 pop, push만 적절한 때에 해주면
굳이 원형큐 사용할 필요 없음
*/

void rotate(){
	belt.push_front(belt.back());
	belt.pop_back();
	
	robot.push_front(robot.back());
	robot.pop_back();
	robot[N-1]=false; //로봇 내림
}

void move(){
	for(int i=N-2;i>=0;i--){
		if(robot[i+1]==false&&belt[i+1]>=1&&robot[i]==true){ //로봇이 있어야 내리지
			robot[i+1]=true;
			robot[i]=false;
			belt[i+1]--;
			
			if(belt[i+1]==0)
				cnt++;
		}
	}
	robot[N-1]=false;
}

void upward(){
	if(robot[0]==false&&belt[0]>0){
		robot[0]=true;
		belt[0]--;
		
		if(belt[0]==0)
			cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>K;
	
	for(int i=0;i<2*N;i++){
		int k;
		cin>>k;
		
		belt.push_back(k);
		robot.push_back(false);
	}
	
	while(true){
		if(cnt>=K)
			break;
		level++;
		rotate();
		move();
		upward();
	}
	cout<<level;
}
