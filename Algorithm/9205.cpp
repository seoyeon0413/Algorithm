#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct coordinate {
	int x;
	int y;
}C ;

vector <C> cood[105];

int distance(C a, C b) {
	int d = abs(a.x - b.x) + abs(a.y - b.y);

	return d;
}

string happyORSad(int num, C house, C cStore[], C rockF) {
	int beer = 20;

	if (distance(house, rockF) <= beer * 50) {	//집에서 락페스티벌까지 한번에 갈 수 있는 경우
		return "happy";
	}
	
	

}

int main(void)
{
	int t, n;
	C h;		//house coordinate
	C cs[101];	//convenient Store coordinate
	C rf;		//rock festival coordinate
	string result[51];

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> h.x >> h.y;

		for (int j = 0; j < n; j++) {
			cin >> cs[i].x >> cs[i].y;
		}

		cin >> rf.x >> rf.y;

		result[i] = happyORSad(n, h, cs, rf);
	}


	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}


	return 0;
}