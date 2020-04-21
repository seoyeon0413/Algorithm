#include <stdio.h>
#include <math.h>

int main(void)
{
	int num;

	int k = 1;
	int digit = 1;

	scanf("%d", &num);

	while (1) {
		if ((num / k) < 10)
			break;
		else {
			digit = digit + 1;
			k *= 10;
		}
	}

	int newNum = 0;
	int n[100000];
	for (int i = 0; i < digit; i++) {
		n[i] = (int)(num / pow(10, i)) % 10;
	}

	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < digit - 1 - i; j++) {
			if (n[j] < n[j + 1]) {
				int temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < digit; i++) {
		printf("%d", n[i]);
	}

	return 0;
}
/*
#include <stdio.h>
#include <math.h>

int main(void)
{
	int num;

	int k = 1;
	int digit = 1;

	scanf("%d", &num);

	while (1) {
		if ((num / k) < 10)
			break;
		else {
			digit = digit + 1;
			k *= 10;
		}
	}

	int newNum = 0;
	for (int i = 0; i < digit; i++) {
		int n = (int)(num / pow(10, i)) % 10;
		newNum = newNum + (n * pow(10, digit-i-1));
	}

	printf("%d", newNum);

	return 0;
}
*/
//2*1000 + 1*100 + 4*10 + 3*1
//3*1000 + 4*100 + 1*10 + 2*1
/*
[�������]
1. % -> int���� ���ؼ��� ��� ����.
2. �ڸ��� ���ϱ�
	: 10���� ������ ���� ���� 10���� ���� ��찡 �ִ� �ڸ���
3. ���� ������
	: �ڸ��� ������ ���� �ϱ� ((num / pow(10,i)) % 10 ) => �Ųٷ� ����.
*/