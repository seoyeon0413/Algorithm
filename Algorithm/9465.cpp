#include <iostream>
#include <algorithm>

using namespace std;

int t, n;
int m = 0;
int d[3][100001];
int r[3][100001];

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> d[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			r[0][i] = d[0][i] + max(r[1][i - 1], r[1][i - 2]);
			r[1][i] = d[1][i] + max(r[0][i - 1], r[0][i - 2]);
		}

		cout << max(r[0][n - 1], r[1][n - 1]) << endl;
	}

	return 0;
}
