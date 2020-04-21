#include <stdio.h>
typedef struct person {
	int age;
	char name[101];
}P;

int sorted[1000];
P sStruct[1000];
P p[1000];

void merge(int a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			sStruct[k] = p[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			sStruct[k] = p[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			sStruct[k] = p[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			sStruct[k] = p[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
		p[t] = sStruct[t];
	}
}
void mergeSort(int a[], int m, int n)
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
	int ageArray[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %s", &p[i].age, &p[i].name);
	}

	for (int i = 0; i < n; i++) {
		ageArray[i] = p[i].age;
	}

	mergeSort(ageArray, 0, n - 1);


	for (int i = 0; i < n; i++) {
		printf("%d %s\n", p[i].age, p[i].name);
	}

	return 0;
}