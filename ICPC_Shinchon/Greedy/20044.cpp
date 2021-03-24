#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,tmp,ans;
vector<int> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>n;
	n*=2;
	
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	
	sort(v.begin(),v.end());
	ans=1234567891;
	
	for(int i=0;i<n/2;i++){
		tmp=v[i]+v[n-1-i];
		ans=min(tmp,ans);
	}
	
	cout<<ans;
}
