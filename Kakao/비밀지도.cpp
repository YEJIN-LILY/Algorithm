#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string map(int n){
	string s="";
	while(n!=0){
		if(n%2==0)
			s+=' ';
		else
			s+='#';
		n/=2;
	}
	
	reverse(s.begin(),s.end());
	return s;
}

vector<string> solution(int n,vector<int> arr1,vector<int> arr2){
	vector<string> answer;
	
	for(int i=0;i<n;i++){
		int k=arr1[i]|arr2[i]; //하나라도 1이면 1 반환, 모두 0일때만 0반환
		//cout<<k<<endl;
		answer.push_back(map(k));
	}
	
	for(int i=0;i<n;i++)
		cout<<answer[i]<<endl;
	return answer;
}



int main(){
	int n=5;
	//int n=6;
	
	vector<int> arr1={9,20,28,18,11};
	vector<int> arr2={30,1,21,17,28};
	
	//vector<int> arr1={46,33,33,22,31,50};
	//vector<int> arr2={27,56,19,14,14,10};
	
	solution(n,arr1,arr2);
}
