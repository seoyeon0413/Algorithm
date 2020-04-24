#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[11];
	int kScore;
	int eScore;
	int mScore;
}Std;

Std sorted[1000];
Std s[1000];

void merge(Std *a, int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i].kScore > a[j].kScore) {	//국어 점수가 감소하는 순서로
			sorted[k] = a[i];
			i++;
		}
		else if (a[i].kScore == a[j].kScore) {
			if (a[i].eScore < a[j].eScore) {	//국어 점수가 같으면 영어 점수가 증가하는 순서로
				sorted[k] = a[i];
				i++;
			}
			else if (a[i].eScore == a[j].eScore) {
				if (a[i].mScore > a[j].mScore) {	//국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
					sorted[k] = a[i];
					i++;
				}
				else if (a[i].mScore == a[j].mScore) {	//모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로
					if (strcmp(a[i].name, a[j].name) < 0) {
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

void mergeSort(Std *a, int m, int n)
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

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s %d %d %d", s[i].name, &s[i].kScore, &s[i].eScore, &s[i].mScore);
	}

	mergeSort(s, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%s\n", s[i].name);
	}


	return 0;
}