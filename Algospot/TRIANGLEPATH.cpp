#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int triangle[100][100];
int sum[100][100];
int n;

int findSum(int y,int x){
	if(y==n-1)
		return triangle[y][x];
	
	int& ret=sum[y][x];
	
	if(ret!=-1)
		return ret;
	
	return ret=triangle[y][x]+max(findSum(y+1,x),findSum(y+1,x+1));
}

int main(){
	int c;
	cin>>c;
	
	for(int i=0;i<c;i++){
		cin>>n;
		memset(sum,-1,sizeof(sum));
		for(int j=0;j<n;j++){
			for(int k=0;k<=j;k++){
				cin>>triangle[j][k];
			}
		}
		
		cout<<findSum(0,0)<<endl;
	}
}
