#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
배열이 매우 크기 때문에 전부 압축해재하고 다시 반전시켜 압축하기에는 메모리와 시간이 많이 든다.
재귀적으로 호출할 때, 기저 사례는 w나 b일 경우: 이 때 리턴
압축을 풀기 위해서는 1,2,3,4사분면 차례로 호출해야 한다->**이 때 인덱스 변경을 반영하기 위해 iterator사용!!**
리턴값은 반전시킨 결과: 3,4,1,2 순으로
*/
string reverse(string::iterator& iter){
	char head=*iter; //현재 글자
	iter++; //다음 글자로 이동
	
	if(head=='w'||head=='b') //기저 사례
		return string(1,head); //head 1개 리턴
	
	//글자가 'x'일 경우(다시 재귀적으로 4분할하여 호출)
	//iter값 계속 변동(1씩 증가)
	string first=reverse(iter);
	string second=reverse(iter);
	string third=reverse(iter);
	string fourth=reverse(iter);
	
	return string("x")+third+fourth+first+second;
}

int main(){
	int c;
	scanf("%d",&c);
	
	vector<string> answer;
	
	for(int i=0;i<c;i++){
		string s;
		cin>>s;
		
		string:: iterator it=s.begin();
		string a=reverse(it);
		
		answer.push_back(a);
	}
	
	for(int i=0;i<answer.size();i++)
		cout<<answer[i]<<endl;
}
