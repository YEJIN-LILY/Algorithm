#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N,M,ans,cnt;
deque<int> is_multiple;
deque<int> rest;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		int k;
		cin>>k;
		if(k%10==0){
			is_multiple.push_back(k);
		}
		else
			rest.push_back(k);
	}
	
	
	sort(is_multiple.begin(),is_multiple.end()); //작은 것 먼저 자르는 것이 이득
	
	while(!is_multiple.empty()){
		int a = is_multiple[0]/10; //최대로 얻을 수 있는 빵의 개수
		int divide=min(a-1,M); //자를 수 있는 횟수
		
		if(is_multiple[0]==10){
			cnt++;
			is_multiple.pop_front();
		}
		else if(M<0)
			break;
		else if(divide==a-1){ //해당 빵을 다 자를 수 있을 때
			cnt+=a;
			M-=divide;
			is_multiple.pop_front();
		}else if(divide==M){ //해당 빵을 다 자르지 못할 때
			cnt+=M;
			M-=divide;
			is_multiple.pop_front();
		}
	}
	
	//10의 배수가 아닌 롤케이크 처리
	sort(rest.begin(),rest.end());
	
	while(!rest.empty()&&M>0){
		if(M<0)
			break;
		if(rest[0]<10){ //10보다 작으면 볼 필요가 없다!!!
			rest.pop_front();
			continue;
		}
		int a = rest[0]/10; //최대로 얻을 수 있는 빵의 개수
		int divide=min(a,M); //자를 수 있는 횟수
		
		M-=divide;
		cnt+=divide;
		
		rest.pop_front(); 
	}
	
	cout<<cnt;
}
