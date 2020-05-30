#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int main()
{
	int n, w = 2;
	int a[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, a[i] * (n - i));
	}

	cout << m;


	return 0;
}
