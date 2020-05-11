#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct coordinate {
	int x;
	int y;
	bool check = false;
}C ;

C cs[101];	//convenient Store coordinate, 첫번째 좌표는 집
C rf;		//rock festival coordinate

int distance(C a, C b) {
	int d = abs(a.x - b.x) + abs(a.y - b.y);

	return d;
}

int r = 0;
int happyORSad(int num, int index) {	//1 - 성공, 0 - 실패
	if (distance(cs[index], rf) <= 1000) {	//집에서 락페스티벌까지 한번에 갈 수 있는 경우
		return 1;
	}

	for (int i = index; i < num; i++) {
		if ((distance(cs[index], cs[i]) <= 1000) && (cs[i].check == false)) {	//index = 현재 편의점, i = 다음 편의점
			cs[i].check = true;
			r = happyORSad(num, i);
		}
		if (r == 1) {
			r = 0;
			return 1;
		}
	}

	return 0;
}

int main(void)
{
	int t, n;
	int result[101];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		n++;	//집까지 포함
		for (int j = 0; j < n; j++) {
			cin >> cs[j].x >> cs[j].y;
			if (j == 0) {	//집은 언제나 방문
				cs[j].check = true;
			}
		}

		cin >> rf.x >> rf.y;

		result[i] = happyORSad(n, 0);
	}


	for (int i = 0; i < t; i++) {
		if (result[i] == 1) {
			cout << "happy" << endl;
		}
		else {
			cout << "sad" << endl;
		}
	}


	return 0;
}