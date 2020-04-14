#include <stdio.h>
int main(void)
{
	int i, j, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9-i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	//Result
	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}
/*
bubble sort -> sort�߿��� ���� ��ȿ������ ���
bubble sort: �ѹ� �ݺ���, ���� ū ���� �� �ڷ� �Ű����� ���
selection sort�� �տ������� �������� bubble sort�� �ڿ������� �񱳰� ����.

�� ���� ������ �ð� ���⵵
10 + 9 + 8 + ... + 2 + 1
=> 10 * (10 + 1) / 2 = 55
=> N * (N + 1) / 2
=> O (N * N)
*/