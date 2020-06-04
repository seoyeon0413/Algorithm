#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	int result = 0;

	cin >> n >> m;
	if (n == 1)
		cout << 1;
	else if (n == 2) {
		if ((m + 1) / 2 > 4)
			cout << 4;
		else
			cout << (m + 1) / 2;
	}
	else {
		if (m >= 7)
			cout << m - 2;
		else
			cout << min(m, 4);
	}
	

	return 0;
}
