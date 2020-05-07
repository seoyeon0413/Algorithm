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

string happyORSad(int num, int index) {
	if (distance(cs[index], rf) <= 1000) {	//집에서 락페스티벌까지 한번에 갈 수 있는 경우
		return "happy";
	}

	for (int i = 0; i < num; i++) {
		if ((distance(cs[i], rf) <= 1000) && (cs[i].check == false)) {
			cs[i].check = true;
		}
		else {
			index++;
			return happyORSad(num, index);
		}
	}

	return "sad";
}

int main(void)
{
	int t, n;
	string result[51];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		
		n++;	//집까지 포함
		for (int j = 0; j < n; j++) {
			cin >> cs[j].x >> cs[j].y;
		}

		cin >> rf.x >> rf.y;

		result[i] = happyORSad(n, 0);
	}


	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}


	return 0;
}