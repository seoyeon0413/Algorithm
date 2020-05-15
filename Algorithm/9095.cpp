#include <iostream>

using namespace std;

int num[11];

int dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;
	if (x == 3)
		return 4;

	return num[x] = dp(x - 1) + dp(x - 2) + dp(x - 3);
}

int main()
{
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp(n) << endl;
	}

	return 0;
}
