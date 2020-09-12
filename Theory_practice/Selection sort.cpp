#include <iostream>
using namespace std;

//O(n^2)
//가장 작은 것을 맨 앞으로
class Sort {
	int num[10];

public:
	Sort(int* values) {
		for (int i = 0; i < 10; i++)
			num[i] = values[i];
	}

	void print() {
		for (int i = 0; i < 10; i++)
			cout << num[i] << ' ';
		cout << endl;
	}

	void selection() {
		int i, j, index, min;
		for (i = 0; i < 9; i++) {
			min = num[i];
			index = i;
			for (j = i+1; j < 10; j++) {
				if (min > num[j]) {
					min = num[j];
					index = j;
				}
			}
			num[index] = num[i];
			num[i] = min;
		}
	}
};

int main() {
	int nums[10] = { 1,10,5,8,7,6,4,3,2,9 };
	Sort s(nums);

	s.print();
	s.selection();
	s.print();
}
