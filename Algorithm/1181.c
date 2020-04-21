#include <stdio.h>
#include <string.h>

char sorted[1000][51];
char str[1000][51];

void merge(char *a[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터도 삽입
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
	//정렬된 배열을 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n)
{
	//이외의 경우는 크기가 1개인 경우
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

	scanf("%d%*c", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", &str[i]);
	}

	mergeSort(str, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", str[i]);
	}

	return 0;
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[1000][50] = { " " };


    scanf("%d%*c", &n);

    for (int i = 0; i < n; i++) {
        //gets(str[i]);
        scanf("%s", &str[i]);
    }

    char temp[50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strlen(str[j]) > strlen(str[j + 1])) {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
            else if (strlen(str[j]) == strlen(str[j + 1])) {
                if (strcmp(str[j], str[j + 1]) == 0) {
                    for (int k = j; k < n - 1; k++) {
                        strcpy(str[k], str[k + 1]);
                    }
                    n--;
                }
                if (strcmp(str[j], str[j + 1]) > 0) {
                    strcpy(temp, str[j]);
                    strcpy(str[j], str[j + 1]);
                    strcpy(str[j + 1], temp);
                }
            }

        }
    }

    for (int i = 0; i < n; i++) {
        puts(str[i]);
    }

    return 0;
}
*/
// scanf_s("%d%*c", &n); --> gets랑 같이 사용시.
// scanf("%s", &name[i]);