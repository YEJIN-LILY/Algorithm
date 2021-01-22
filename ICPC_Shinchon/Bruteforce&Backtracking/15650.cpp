#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10

using namespace std;
int n,m;

bool isused[MAX];
int answer[MAX];

void solution(int depth,int start){
	if(depth==m){
		for(int i=0;i<depth;i++)
			cout<<answer[i]<<' ';
		cout<<'\n';
	}
	
	for(int i=start;i<=n;i++){
		if(isused[i])
			continue;
		isused[i]=true;
		answer[depth]=i;
		solution(depth+1,i+1);
		isused[i]=false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n>>m;
	
	solution(0,1);
}
