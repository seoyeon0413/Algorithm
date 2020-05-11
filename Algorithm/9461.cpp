#include <iostream>

using namespace std;

long long tri[1000];

long long dp(int x)
{
	if (x == 1 || x == 2 || x == 3)
		return 1;
	if (x == 4 || x == 5)
		return 2;
	if (x == 6)
		return 3;

	if (tri[x] != 0)
		return tri[x];

	return tri[x] = dp(x - 2) + dp(x - 3);
}

int main()
{
	int t, n;
	long long result[1000];

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp(n) << endl;
	}


	return 0;
}