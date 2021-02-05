#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
using namespace std;

vector<string> answer;

void isCorrect(string s){
	stack<char> st;
	bool flag=true;
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='('||s[i]=='[')
			st.push(s[i]);
		else if(s[i]==')'){
			if(!st.empty()&&st.top()=='(') //empty() 함수가 항상 앞에 있어야 함! or segmentation false
				st.pop();
			else{
				flag=false;
				break;
			}
		}else if(s[i]==']'){
			if(!st.empty()&&st.top()=='[')
				st.pop();
			else{
				flag=false;
				break;
			}
		}
	}
	
	if(st.empty()&&flag==true)
		answer.push_back("yes");
	else
		answer.push_back("no");
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    string s;
	
	while(true){
		getline(cin,s);
		if(s.length()==1&&s[0]=='.')
			break;
		isCorrect(s);
		
	}
	
	for(int i=0;i<answer.size();i++)
		cout<<answer[i]<<"\n";
}
