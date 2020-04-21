#include <stdio.h>

int main(void)
{
	int num;
	int array[100001];

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}