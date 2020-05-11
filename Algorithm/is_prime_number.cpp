//에라토스테네스의 체 : 여러 개의 소수를 한꺼번에 판별하고자 할 때 사용.
#include <stdio.h>

int number = 100000;
int a[100001];

void primeNumberSieve()
{
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}
	
	for (int i = 2; i <= number; i++) {
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i) {	//특정 숫자의 배수에 해당하는 숫자를 모두 지움(j += i), 자기 자신 제외(j = i + i).
			a[j] = 0;
		}
	}

	for (int i = 2; i <= number; i++) {
		if (a[i] != 0)
			printf("%d ", a[i]);
	}

}

int main()
{
	primeNumberSieve();

	return 0;
}

/*
#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x)
{
	int end = (int)sqrt(x);	//8 = 2 * 4 = 4 * 2 --> 대칭을 이룸 --> 제곱근까지만 약수의 여부를 판별하면 모두 판별하는 것임.

	for (int i = 2; i <= end; i++) {
		if (x % i == 0)
			return false;

		return true;
	}


}
int main()
{
	printf("%d", isPrimeNumber(97));

	return 0;
}
*/