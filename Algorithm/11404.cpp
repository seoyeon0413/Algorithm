#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int INF = 1000000000;
int d[101][101];

void floydWarshall()
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
			}
		}
	}

	//결과값 -> INF도 0으로 바꿔주기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (d[i][j] == INF)
				d[i][j] = 0;

			cout << d[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	int start = 0, end = 0;
	int distance;

	cin >> n >> m;

	//도착 지점과 출발 지점이 같을 경우, 0으로 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> start >> end >> distance;

		if (distance > d[start - 1][end - 1])
			continue;
		
		d[start - 1][end - 1] = distance;
	}

	floydWarshall();

	return 0;
}