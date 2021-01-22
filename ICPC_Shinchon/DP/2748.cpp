#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using ll=long long;

ll fib[100];

ll solution(int n){ //top-down 방식
	if(n==0||n==1)
		return fib[n]=n;
	if(fib[n]!=-1)
		return fib[n];
	
	return fib[n]=solution(n-1)+solution(n-2); //대입 후 리턴
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin>>n;
	
	for(int i=0;i<100;i++)
		fib[i]=-1;
	
	cout<<solution(n);
}
