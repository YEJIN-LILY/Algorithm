#include <iostream>
using namespace std;

//병합정렬(merge sort)->분할정복
//O(n*logn)

class Merge {
	int sorted[8]; //임시배열->메모리 비효율적
	int num[8];
public:
	Merge(int* values) {
		for (int i = 0; i < 8; i++)
			num[i] = values[i];
	}

	void print() {
		for (int i = 0; i < 8; i++)
			cout << sorted[i] << ' ';
	}

	void merge(int start,int middle,int end) {
		int i = start;
		int j = middle + 1;
		int k = start;

		//작은 순서대로 배열 삽입
		while (i <= middle && j <= end) {
			if (num[i] <= num[j]) {
				sorted[k] = num[i];
				i++;
			}
			else {
				sorted[k] = num[j];
				j++;
			}
			k++;
		}

		//남은 데이터 삽입
		if (i > middle) { //왼쪽 배열이 먼저 다끝났을 경우 오른쪽 배열 그대로 넣어줌
			for (int t = j; t <= end; t++) {
				sorted[k] = num[t];
				k++;
			}
		}
		if (j > end) {
			for (int t = i; t <= middle; t++) {
				sorted[k] = num[t];
				k++;
			}
		}

		for (int t = start; t <= end; t++) {
			num[t] = sorted[t];
		}

	}

	void mergeSort(int start, int end) {
		if (end > start) {
			int middle = (start + end) / 2;
			mergeSort(start, middle); //분할정렬
			mergeSort(middle + 1, end); //분할정렬
			merge(start, middle, end); //합치기
		}
	}
};

int main() {
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	Merge m(arr);

	m.mergeSort(0, 7);
	m.print();
}
