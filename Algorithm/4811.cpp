#include <iostream>

using namespace std;
/*
n = 2 | C2 = C0C2 + C1C1 + C2C0
2
n = 3 | C3 = C0C3 + C1C2 + C2C1 + C3C0
5
n = 4 | C4 = C0C4 + C1C3 + C2C2 + C3C1 + C4C0
14
*/
/*
	한 조각을 꺼낸 날 = W
	반 조각을 꺼낸 날 = H

	- n = 1 (1개)
	2일 ->	WH
	-> 답: 1

	- n = 2 (2개)
	4일 ->	WWHH, WHWH
	-> 답: 2

	- n = 3 (3개)
	6일 ->	WWWHHH, WWHWHH, WWHHWH, WHWWHH, WHWHWH
	-> 답: 5

	*/

/*
long long bin[31][31];

long long binomial(long long bin[][31], int n, int k) {
	if (n == k or k == 0) {
		return 1;
	}
	else if (bin[n][k] > 0) {
		return bin[n][k];
	}
	else {
		bin[n][k] = binomial(bin, n - 1, k) + binomial(bin, n - 1, k - 1);
		return bin[n][k];
	}
}

long long catalan(int n) {
	return binomial(bin, 2 * n, n) - binomial(bin, 2 * n, n + 1);
}
*/
long long int c[1001];

long long int catalan(int n)
{
	// Base case 
	if (n <= 1)
		return 1;

	if (c[n] != 0)
		return c[n];

	// catalan(n) is sum of catalan(i)*catalan(n-i-1) 
	for (int i = 0; i < n; i++) {
		c[n] += catalan(i) * catalan(n - i - 1);
	}

	return c[n];
}

int main() {
	int n = 0;
	long long int resultArray[1001];

	int num = 0;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		resultArray[num] = catalan(n);
		num++;
	}

	for (int i = 0; i < num; i++) {
		cout << resultArray[i] << endl;
	}

	return 0;
}
// dynamic programming을 사용해야지 '시간초과'가 나지 않음.
/*
공식 따로 있음...
Cn = (2n)! / ((n+1)!n!)
*/