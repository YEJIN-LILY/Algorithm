#include <iostream>
#include <vector>
using namespace std;

int N,ans,cnt,cur_max;
vector<int> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>N;
	
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		
		v.push_back(a);
	}
	
	
	for(int i=0;i<v.size();i++){
		if(cur_max<v[i]){//자기보다 작은 봉우리는 볼 필요가 없음->항상 자기가 처치한 적의 개수가 많을 것이기 때문
			cur_max=v[i];
			ans=max(ans,cnt);
			cnt=0;
		}else{
			cnt++;
		}
	}
	
	ans=max(ans,cnt); //내림차순으로 정렬되어 있을 때를 대비해 다시 한 번 체크!
	cout<<ans;
}
