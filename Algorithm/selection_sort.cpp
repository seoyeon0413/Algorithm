#include <stdio.h>
int main(void)
{
	int i, j, min, index, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 10; i++) {
		min = 9999;	//�׻� �ּڰ��� �����ؾ߶����� ó������ ū ���� �����.
		
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}

		temp = array[index];
		array[index] = array[i];
		array[i] = temp;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}

/*
�� ���� ������ �ð� ���⵵
10 + 9 + 8 + ... + 2 + 1
=> 10 * (10 + 1) / 2 = 55
=> N * (N + 1) / 2
=> O (N * N)
*/