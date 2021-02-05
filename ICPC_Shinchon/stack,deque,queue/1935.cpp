#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

#define ll long long

double num[26];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cout<<fixed;
	cout.precision(2);
	
	double N;
	cin>>N;
	
	string s;
	cin>>s;
	
	stack<double> st;
	
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	for(double i=0;i<s.length();i++){
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			double n2=st.top();
			st.pop();
			double n1=st.top();
			st.pop();
			
			double result;
			
			switch(s[i]){
				case '+':
					result=n1+n2;
					st.push(result);
					break;
				case '-':
					result=n1-n2;
					st.push(result);
					break;
				case '*':
					result=(1.0)*n1*n2;
					st.push(result);
					break;
				case '/':
					result=(1.0)*n1/n2;
					st.push(result);
					break;
			}
		}else{
			st.push(num[s[i]-'A']);
		}
	}
	
	cout<<st.top();
}
