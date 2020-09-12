#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) { //내림차순
	return a > b;
}

int main() {
	int a[10] = { 9,3,5,4,1,10,8,6,7,2 };
	sort(a, a + 10,compare); //시작주소~마지막 주소
	//sort:기본은 오름차순

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
}
