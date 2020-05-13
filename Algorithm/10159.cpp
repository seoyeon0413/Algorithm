#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
int INF = 1000000000;
int n, m;
/*
int arr[6][6] = {
	{0, 1, INF, INF, INF, INF},
	{INF, 0, 1, INF, INF, INF},
	{INF, INF, 0, 1, INF, INF},
	{INF, INF, INF, 0, INF, INF},
	{INF, INF, INF, 1, 0, INF},
	{INF, INF, INF, INF, 1, 0}
};
*/
void floydWarshall()
{
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
}

int main()
{
	int a, b;
	int count = 0;

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;

		arr[a][b]++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				arr[i][j] = INF;
			if (i == j)
				arr[i][j] = 0;
		}
	}

	floydWarshall();

	//결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) {
				cout << "INF ";
				continue;
			}
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != INF)
				arr[j][i] = arr[i][j];
		}
	}


	//결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF) {
				cout << "INF ";
				continue;
			}
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == INF)
				count++;
		}
		cout << count << endl;
		count = 0;
	}

	return 0;
}
/*
6
5
1 2		[0][1] = 1
2 3		[1][2] = 1
3 4		[2][3] = 1
5 4		[4][3] = 1
6 5		[5][4] = 1

1>2
2>3
3>4
5>4
6>5

1>2>3>4
6>5>4
*/