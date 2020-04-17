#include <stdio.h>
#include <math.h>

void main() 
{
	int n;
	int a[1000], b[1000];
	int s = 0;

	scanf_s("%d", &n);

	//array a
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	//array b
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &b[i]);
	}

	/*
5
1 1 1 6 0				i
|2 7 8 3 1 -> 4(4)		0
1| 7 8 3 2 -> 4(0) =	1
1 2| 8 3 7 -> 3(3) =	2
1 2 3| 8 7 -> 4(1) =	3
1 2 3 7| 8 -> 4(2) =	4
1 2 3 7 8 (done)

index: 4 0 3 1 2

2 7 8 3 1 -> 4(4)
2 7 8 3 -> 0(0)
7 8 3 -> 2(3)
7 8 -> 0(1)
8 -> 0(2)

1 1 0 1 6
*/
	int min[1000] = { 9999 };
	int index[1000];
	int state = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && (min[i] > b[j])) {
				min[i] = b[j];
				index[i] = j;
			}

			if (i > 0 && (min[i] > b[j])) {
				for (int k = 0; k < i; k++) {
					if (min[k] < min[i]) {
						min[i] = b[j];
						index[i] = j;
					}
				}
			}
		}
	}

	printf("\nmin");
	for (int i = 0; i < n; i++) {
		printf("%d ", min[i]);
	}

	printf("\nindex");
	for (int i = 0; i < n; i++) {
		printf("%d ", index[i]);
	}


}