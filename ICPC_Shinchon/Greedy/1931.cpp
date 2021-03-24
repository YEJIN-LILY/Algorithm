#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,a,b,cnt,finish_time;
vector<pair<int,int>> times;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>a>>b;
		
		times.push_back({b,a}); //끝나는 시간, 시작 시간
	}
	
	sort(times.begin(),times.end());
	finish_time=times[0].first;
	cnt=1;
	
	for(int i=1;i<times.size();i++){
		if(times[i].second>=finish_time){
			finish_time=times[i].first;
			cnt++;
		}
	}
	
	cout<<cnt;
}
