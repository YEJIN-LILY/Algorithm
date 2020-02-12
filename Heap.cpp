#include <iostream>
using namespace std;

class Heap {
	int heap[9];
public:
	Heap(int* values) {
		for (int i = 0; i < 9; i++) {
			heap[i] = values[i];
		}
	}
	void sort() { 
		for (int i = 1; i < 9; i++) { //최대 힙 구조로 만든다
			int c = i;
			do {
				int root = (c - 1) / 2;
				if (heap[root] < heap[c]) {
					int tmp = heap[root];
					heap[root] = heap[c];
					heap[c] = tmp;
				}
				c = root;
			} while (c != 0);
		}

		for (int i = 0; i < 9; i++)
			cout << heap[i] << ' ';
		cout << endl;

		//크기 줄여가며 반복적으로 힙 구성
		for (int i = 8; i >= 0; i--) {
			int tmp = heap[0]; //루트는 무조건 큰 값이 있기 때문에 먼저 바꿔준다
			heap[0] = heap[i];
			heap[i] = tmp;
			int root = 0;
			int c = 1; //자식
			do {
				c = 2 * root + 1; //자식노드
				if (heap[c] < heap[c + 1] && c < i - 1) //자식 중에 더 큰 값 찾기
					c++;
				if (heap[root] < heap[c] && c < i ) {
					tmp = heap[root];
					heap[root] = heap[c];
					heap[c] = tmp;
				}
				root = c;
			} while (c<i);
		}

		for (int i = 0; i < 9; i++)
			cout << heap[i] << ' ';
		cout << endl;
	}

};
int main() {
	int num[9] = { 7,6,5,8,3,5,9,1,6 };

	Heap heap(num);
	heap.sort();
}
