#include <iostream>
using namespace std;

//O(n)
//데이터의 값에 영향받음
class Count {
	int num[30];
	int count[6];
public:
	Count(int* values) {
		for (int i = 0; i < 30; i++)
			num[i] = values[i];
	}

	void print() {
		for (int i = 1; i < 6; i++) {
			int n = count[i];
			for (int j = 0; j < n; j++) {
				cout << i << ' ';
			}
		}
	}

	void sort() {
		for (int i = 1; i < 6; i++)
			count[i] = 0;
		for (int i = 0; i < 30; i++) {
			count[num[i]]++;
		}
	}
};
int main() {
	int arr[30] = { 1,3,2,4,3,2,5,3,1,2,3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1 };

	Count c(arr);
	c.sort();
	c.print();
}
