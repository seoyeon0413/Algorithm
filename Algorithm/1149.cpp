#include <iostream>
#include <algorithm>

using namespace std;

int rgb[1005][4];
int cost[1005][4];

int main()
{
	int N;
	int result = 0;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
		rgb[i][0] = min(rgb[i - 1][1], rgb[i - 1][2]) + cost[i][0];	//첫번째 r, 두번째는 g,b중에 작은 값
		rgb[i][1] = min(rgb[i - 1][0], rgb[i - 1][2]) + cost[i][1];	//첫번째 g, 두번째는 r,b중에 작은 값
		rgb[i][2] = min(rgb[i - 1][0], rgb[i - 1][1]) + cost[i][2];	//첫번째 b, 두번째는 r,g중에 작은 값
	}

	result = min(min(rgb[N][0], rgb[N][1]), rgb[N][2]);
	cout << result;

	return 0;
}
/*
rgb[][]는 계속 업데이트됨.
rgb[1][] = rgb[0][] + cost[1][];
rgb[2][] = rgb[1][] + cost[2][];
rgb[3][] = rgb[2][] + cost[3][];
rgb[4][] = rgb[3][] + cost[4][];
...
rgb[N][] = rgb[N-1][] + cost[N][];
*/
