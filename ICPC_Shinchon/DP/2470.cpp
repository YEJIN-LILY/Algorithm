#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cache[101][101];
int n,m;

string string_add(const string a,const string b){
	long long sum=0;
	string copy1(a);
	string copy2(b);
	string tmp;
	
	while(!copy1.empty()||!copy2.empty()||sum){
		if(!copy1.empty()){
			sum+=copy1.back()-'0';
			copy1.pop_back();
		}
		if(!copy2.empty()){
			sum+=copy2.back()-'0';
			copy2.pop_back();
		}
		tmp.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(tmp.begin(),tmp.end());
	return tmp;
}

string combination(int a,int b){
	string& ret=cache[a][b];
	
	if(ret!="")
		return ret;
	else if(a==b||b==0)
		return ret='1';
	else
		return ret=string_add(combination(a-1,b-1),combination(a-1,b));
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	cout<<combination(n,m);
}
