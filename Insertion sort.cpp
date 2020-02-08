#include <iostream>
using namespace std;


//O(n^2)
//필요할 때만 위치를 바꾼다->같은 시간복잡도를 갖는 알고리즘 중 가장 빠르다

class Insertion {
	int num[10];
public:
	Insertion(int* values) {
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
		for (i = 0; i < 9; i++) {
			j = i;
			while (num[j] > num[j + 1]) { //옆에 있는 것끼리 비교
				tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
				j--; //왼쪽으로 이동하면서
			}
			if (j < 0)
				break;
		}
	}
};
int main() {
	int nums[10] = { 1,10,5,8,7,6,4,3,2,9 };

	Insertion b(nums);
	b.sort();
	b.print();
}
