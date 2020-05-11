#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef struct coordinate {
	int x;
	int y;
	bool check = false;
}C ;

C cs[101];	//convenient Store coordinate, ù��° ��ǥ�� ��
C rf;		//rock festival coordinate

int distance(C a, C b) {
	int d = abs(a.x - b.x) + abs(a.y - b.y);

	return d;
}

int r = 0;
int happyORSad(int num, int index) {	//1 - ����, 0 - ����
	if (distance(cs[index], rf) <= 1000) {	//������ ���佺Ƽ������ �ѹ��� �� �� �ִ� ���
		return 1;
	}

	for (int i = index; i < num; i++) {
		if ((distance(cs[index], cs[i]) <= 1000) && (cs[i].check == false)) {	//index = ���� ������, i = ���� ������
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
		
		n++;	//������ ����
		for (int j = 0; j < n; j++) {
			cin >> cs[j].x >> cs[j].y;
			if (j == 0) {	//���� ������ �湮
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