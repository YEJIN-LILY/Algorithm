#include <iostream>
using namespace std;

int T,N,cnt;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	while(true){
		if(N<0){
			cout<<"-1";
			break;
		}
		else if(N==0){
			cout<<cnt;
			break;
		}
		else if(N%5==0){ //먼저 5로 나눔
			cnt+=N/5;
			cout<<cnt;
			break;
		}else{ //나머지는 3으로 계속 빼주면서
			N-=3;
			cnt++;
		}
	}
}
