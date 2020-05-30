#include <iostream>
#include <algorithm>
using namespace std;

int bambooGrove[501][501];
int d[501][501];
int n;

int dfs(int i, int j) {
	if (d[i][j] != 0)
		return d[i][j];

	int c[4] = { 0, };

	if (i - 1 >= 0) {
		if (bambooGrove[i][j] < bambooGrove[i - 1][j]) {
			c[0]++;
			c[0] += dfs(i - 1, j);
		}
	}
	if (i + 1 < n) {
		if (bambooGrove[i][j] < bambooGrove[i + 1][j]) {
			c[1]++;
			c[1] += dfs(i + 1, j);
		}
	}
	if (j - 1 >= 0) {
		if (bambooGrove[i][j] < bambooGrove[i][j - 1]) {
			c[2]++;
			c[2] += dfs(i, j - 1);
		}
	}
	if (j + 1 < n) {
		if (bambooGrove[i][j] < bambooGrove[i][j + 1]) {
			c[3]++;
			c[3] += dfs(i, j + 1);
		}
	}

	int m = -1;
	for (int k = 0; k < 4; k++) {
		m = max(m, c[k]);
	}

	if (m == 0)
		return 1;

	return d[i][j] = m;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bambooGrove[i][j];
		}
	}

	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = dfs(i, j);
			m = max(m, temp);

		}
	}

	cout << m;

	return 0;
}
