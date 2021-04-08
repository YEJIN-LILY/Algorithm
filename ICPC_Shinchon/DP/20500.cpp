#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define ll long long
#define MOD 1000000007
using namespace std;

ll n;

//일의 자리는 5로 고정해야 함
ll comb[1600][1600]; //comb[x][y]: x->전체 자리수, y->5의 개수=>일의 자리 제외

//15의 배수: 일의 자리는 0 또는 5, 각 자리수 합이 3의 배수

void combination(){
	
	comb[0][0]=1;
	comb[1][0]=1;
	comb[1][1]=1;
	
	for(ll i=2;i<=n;i++){
		comb[i][0]=1;
		comb[i][i]=1;
	}
	
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<=n;j++){
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
			//cout<<"comb["<<i<<"]"<<"["<<j<<"]: "<<comb[i][j]<<endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n;
	
	//n=10;
	
	combination();
	
	ll cnt=0;
	
	//cout<<comb[2][1];
	
	for(ll i=0;i<n;i++){ //5의 개수
		if((n-i-1+5*i+5)%3==0){
			
			cnt+=comb[n-1][i];
		}
	}
	
	cout<<cnt%MOD; 
}
