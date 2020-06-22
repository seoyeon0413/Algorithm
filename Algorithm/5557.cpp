#include <iostream>

using namespace std;

int a[101];
long long d[101][21];

long long dp(int i, int j)
{
	if (i < 0 || j < 0 || j > 20)
		return 0;
	if (i == 1 && j == a[1])
		return 1;
	if (d[i][j] != -1LL)
		return d[i][j];

	return d[i][j] = dp(i - 1, j - a[i]) + dp(i - 1, j + a[i]);
}

int main()
{
	int n;

	cin >> n;
	
	for (int i = 1; i <= 101; i++) {
		for (int j = 1; j <= 21; j++) {
			d[i][j] = -1LL;
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << dp(n - 1, a[n]);

	return 0;
}
