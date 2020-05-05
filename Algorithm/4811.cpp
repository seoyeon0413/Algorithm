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

unsigned long int catalan(unsigned int n)
{
	// Base case 
	if (n <= 1)
		return 1;

	// catalan(n) is sum of catalan(i)*catalan(n-i-1) 
	unsigned long int result = 0;
	for (int i = 0; i < n; i++) {
		result += catalan(i) * catalan(n - i - 1);
	}

	return result;
}

int main() {
	int n = 0;
	long long resultArray[31];

	int num = 0;
	while (1) {
		cin >> n;

		if (n == 0)
			break;

		resultArray[num] = catalan(n);
		//cout << resultArray[num] << endl;
		num++;
	}

	for (int j = 0; j < num; j++) {
		cout << resultArray[j] << endl;
	}

	return 0;

}