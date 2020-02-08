#include <iostream>
using namespace std;

//옆에 있는 값과 비교해서 더 작은 값을 앞으로 보낸다
//가장 큰 값이 맨 뒤로 이동
//O(n^2)
//버블정렬이 선택정렬보다 느리다.
//매번 값들을 교체해야 하기 때문에 더 비효율적(시간이 더 느리다)

class Bubble {
	int num[10];
public:
	Bubble(int* values) {
		for (int i = 0; i < 10; i++)
			num[i] = values[i];
	}

	void print() {
		for (int i = 0; i < 10; i++)
			cout << num[i] << ' ';
		cout << endl;
	}

	void sort() {
		int i, j, tmp;
		for (i = 0; i < 10; i++) {
			for (j =0; j < 9-i; j++) {
				if (num[j] > num[j+1]) {
					tmp = num[j];
					num[j] = num[j+1];
					num[j+1] = tmp;
				}
			}
		}
	}
};
int main() {
	int nums[10] = { 1,10,5,8,7,6,4,3,2,9 };

	Bubble b(nums);
	b.sort();
	b.print();
}
