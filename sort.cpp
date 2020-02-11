#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//정렬기준은 점수가 '작은' 순서
	bool operator< (Student &student) {
		return this->score < student.score;
	}
};

int main() {
	Student students[] = {
		Student("조권",90),
		Student("현빈", 93),
		Student("윤세리",97),
		Student("리정혁",87),
		Student("손예진",92)
	};

	sort(students, students + 5);
	for (int i = 0; i < 5; i++)
		cout << students[i].name << ' ';
}
