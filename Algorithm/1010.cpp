#include <iostream>

using namespace std;

long long d[31][31];

long long dp(int n, int m)
{
	if (n == m)
		return d[n][m] = 1;
	if (n == 1)
		return d[n][m] = m;
	if (d[n][m] != 0)
		return d[n][m];

	return d[n][m] = dp(n, m - 1) + dp(n - 1, m - 1);
}


int main()
{
	int t;
	int n, m;

	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << dp(n, m) << endl;
	}

	return 0;
}
/*
	if (d[n][m] != 0)
		return d[n][m];

이런 형식에서의 다이나믹 프로그래밍에서는
저 조건이 있어야만 시간초과가 안 뜸!!!

*/
