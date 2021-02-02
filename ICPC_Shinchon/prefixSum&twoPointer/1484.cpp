#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

ll g,diff;
vector<ll> A;
vector<ll> answers;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>g;
	
	for(ll i=1;i<=200000;i++)
		A.push_back(i*i);
	
	ll start=0;
	ll end=0;
	
	ll index=0;
	
	while(true){
		if(end>=A.size())
			break;
		diff=A[end]-A[start];
		if(diff==g){
			answers.push_back(sqrt(A[end]));
			end++;
		}
		if(diff<g)
			end++;
		if(diff>g)
			start++;
		
	}
	
	if(answers.size()==0)
		cout<<"-1"<<"\n";
	
	for(int i=0;i<answers.size();i++)
		cout<<answers[i]<<"\n";
	
	
}
