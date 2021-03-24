#include <iostream>
#include <vector>
using namespace std;

int N,cnt,want,ans;
vector<int> score;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		int k;
		cin>>k;
		score.push_back(k);
	}
	
	for(int i=score.size()-1;i>0;i--){
		if(score[i]<=score[i-1]){
			want=score[i]-1;
			cnt=score[i-1]-want;
			ans+=cnt;
			
			score[i-1]=want;
		}
	}
	
	cout<<ans;
}
