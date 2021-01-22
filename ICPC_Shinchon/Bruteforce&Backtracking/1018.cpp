#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<vector<char>> mat;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin>>n>>m;
	
	mat=vector<vector<char>>(n,vector<char>(m,0));
	int answer=n*m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cin>>mat[i][j];
	}
	
	for(int a=0;a<=n-8;a++){
		for(int b=0;b<=m-8;b++){
			int num1=0; //B: 홀수 W: 짝수
			int num2=0; //B: 짝수 W: 홀수
			
			for(int i=a;i<a+8;i++){
				for(int j=b;j<b+8;j++){
					if(mat[i][j]=='W'){
						if((i+j)%2==0)
							num1++;
						else
							num2++;
					}else{
						if((i+j)%2==0)
							num2++;
						else
							num1++;
					}
				}
			}
			
			answer=min(answer,min(num1,num2));
		}
	}
	
	cout<<answer;
}
