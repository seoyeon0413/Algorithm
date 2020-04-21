#include <stdio.h>
typedef struct coordinate {
	int x;
	int y;
}cd;

cd sorted[1000];

void merge(cd *a, int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i].x < a[j].x) {
			sorted[k] = a[i];
			i++;
		}
		else if (a[i].x == a[j].x) {
			if (a[i].y < a[j].y) {
				sorted[k] = a[i];
				i++;
			}
			else {
				sorted[k] = a[j];
				j++;
			}
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(cd *a, int m, int n)
{
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void)
{
	int n;
	cd xy[10000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &xy[i].x, &xy[i].y);
	}

	mergeSort(xy, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", xy[i].x, xy[i].y);
	}

	return 0;
}