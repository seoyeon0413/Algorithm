#include <iostream>

using namespace std;

long long int pn[100];

long long int dp(long long int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 1;

	if (pn[x] != 0)
		return pn[x];
	
	return pn[x] = dp(x - 1) + dp(x - 2);
}

int main()
{
	int n;

	cin >> n;
	cout << dp(n);


	return 0;
}
