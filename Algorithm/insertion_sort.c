#include <stdio.h>

void main()
{
	int i, j, temp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	for (i = 0; i < 9; i++) {
		j = i;
		while (j >= 0 && array[j] > array[j + 1]) {
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
			j--;
		}	
	}


	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
}

/*
◆ 삽입 정렬의 시간 복잡도
10 + 9 + 8 + ... + 2 + 1
=> 10 * (10 + 1) / 2 = 55
=> N * (N + 1) / 2
=> O (N * N)
*/