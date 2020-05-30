#include <iostream>

using namespace std;

int main()
{
	int n, a, r = 0;
	cin >> n;

	int m = 1000 - n;

	a = m / 500;
	r +=a;
	m %= 500;

	a = m / 100;
	r += a;
	m %= 100;

	a = m / 50;
	r += a;
	m %= 50;

	a = m / 10;
	r += a;
	m %= 10;

	a = m / 5;
	r += a;
	m %= 5;

	a = m / 1;
	r += a;
	m %= 1;

	cout << r;

	return 0;
}
