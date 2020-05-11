//�����佺�׳׽��� ü : ���� ���� �Ҽ��� �Ѳ����� �Ǻ��ϰ��� �� �� ���.
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
		for (int j = i + i; j <= number; j += i) {	//Ư�� ������ ����� �ش��ϴ� ���ڸ� ��� ����(j += i), �ڱ� �ڽ� ����(j = i + i).
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
	int end = (int)sqrt(x);	//8 = 2 * 4 = 4 * 2 --> ��Ī�� �̷� --> �����ٱ����� ����� ���θ� �Ǻ��ϸ� ��� �Ǻ��ϴ� ����.

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