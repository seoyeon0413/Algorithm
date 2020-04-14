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
bubble sort -> sort중에서 가장 비효율적인 방식
bubble sort: 한번 반복시, 가장 큰 값이 맨 뒤로 옮겨지는 방식
selection sort는 앞에서부터 비교하지만 bubble sort는 뒤에서부터 비교가 끝남.

◆ 버블 정렬의 시간 복잡도
10 + 9 + 8 + ... + 2 + 1
=> 10 * (10 + 1) / 2 = 55
=> N * (N + 1) / 2
=> O (N * N)
*/