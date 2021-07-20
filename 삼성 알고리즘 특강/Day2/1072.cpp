#include <iostream>
using namespace std;

long long X, Y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> X >> Y;

	long long Z = (Y*100) / X;
	long long win = Z;

	long long start = 0;
	long long end = X; //X번까지만 돌면 됨!
  //(Y+cnt)*100/(X+cnt)=>cnt=X일 때 확률이 올라간다
	long long mid = (start + end) / 2;
	bool flag = false;

	if (Z >= 99) //99이상일 때는 확률이 절대로 올라갈 수 없음
		cout << -1;
	else {
		while (start<end) {
			mid = (start + end) / 2;
			win = ((Y + mid)*100 / (X + mid));

			if (win == Z) {
				start = mid + 1; //mid 의미없음->start를 mid+1로 설정
			}
			else{ //win<Z 인 경우는 절대 존재할 수 없음. win>Z일 때의 else문
				end = mid; //이게 답일수도 있음!!!살려야함
			}
		}
		cout << end;
	}
}
