#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int main()
{
	int n, k, m, r = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		coin.push_back(x);
	}

	for (int i = n - 1; i >= 0; i--) {
		r += k / coin[i];
		k %= coin[i];
	}

	cout << r;


	return 0;
}

//메모리 초과시 '배열' 대신 '벡터' 사용.
