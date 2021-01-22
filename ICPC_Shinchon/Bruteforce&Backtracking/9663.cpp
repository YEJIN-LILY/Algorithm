#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int n,cnt;
bool isused1[40]={false,}; //열
bool isused2[40]={false,}; //우상단: i+j
bool isused3[40]={false,}; //좌상단: i-j -> 이 때 음수 인덱스 처리

void solution(int row){
	if(row==n){
		cnt++;
		return;
	}
	
	for(int j=0;j<n;j++){
		if(isused1[j]||isused2[row+j]||isused3[row-j+n-1])
			continue;
		isused1[j]=true;
		isused2[row+j]=true;
		isused3[row-j+n-1]=true;
		solution(row+1);
		isused1[j]=false;
		isused2[row+j]=false;
		isused3[row-j+n-1]=false;
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n;
	
	solution(0);
	
	cout<<cnt;
}
