#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

long long MOD= 1000000009;
long long MAX =1000000;

using namespace std;

long long mat[1000000];

void solution(){
	mat[1]=1;
	mat[2]=2;
	mat[3]=4;
	
	for(long long i=4;i<=1000000;i++){
		mat[i]=mat[i-1]+mat[i-2]+mat[i-3];
		mat[i]%=MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	long long T;
	cin>>T;
	
	solution();
	
	vector<long long> answer;
	
	for(long long i=0;i<T;i++){
		long long n;
		cin>>n;
		
		answer.push_back(mat[n]);
	}
	
	for(long long i=0;i<T;i++)
		cout<<answer[i]<<endl;
}
