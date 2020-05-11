#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int number = 6000;
int primeNum[6001];
vector<int> vPrimeNumber;

void eratosthenes_sieve()
{
	for (int i = 2; i <= number; i++) {
		primeNum[i] = i;
	}

	for (int i = 2; i <= number; i++) {
		if (primeNum[i] == 0)
			continue;

		for (int j = i + i; j <= number; j += i) {
			primeNum[j] = 0;
		}
	}


	for (int i = 2; i <= number; i++) {
		if (primeNum[i] != 0) {
			vPrimeNumber.push_back(i);
		}
	}
}

void goldbach(int num)
{
	int a, b;
	int check = 0;

	for (int i = 0; i < vPrimeNumber.size(); i++) {
		if (check == 1)
			break;

		a = vPrimeNumber[i];
		
		for (int j = 0; j < vPrimeNumber.size(); j++) {
			if (a == num - vPrimeNumber[j]) {
				if (a >= vPrimeNumber[j]) {
					check = 1;
				}

				b = vPrimeNumber[j];
				break;
			}
		}
	}

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}


	cout << a << ' ' << b << endl;
}

int main()
{
	int t, n;

	eratosthenes_sieve();	//소수 vector 만들기
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		goldbach(n);
	}


	return 0;
}

/*
before, after
------------
10000, 0
10000, 4 (3,7)
4, 4
------------
4, 0 (5,5)
0, 0
*/