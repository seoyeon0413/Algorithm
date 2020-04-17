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
                strcpy_s(temp, 50, str[j]);
                strcpy_s(str[j], 50, str[j + 1]);
                strcpy_s(str[j + 1], 50, temp);
            }
            else if (strlen(str[j]) == strlen(str[j + 1])) {
                if (strcmp(str[j], str[j + 1]) == 0) {
                    for (int k = j; k < n - 1; k++) {
                        strcpy_s(str[k], 50, str[k + 1]);
                    }
                    n--;
                }
                if (strcmp(str[j], str[j + 1]) > 0) {
                    strcpy_s(temp, 50, str[j]);
                    strcpy_s(str[j], 50, str[j + 1]);
                    strcpy_s(str[j + 1], 50, temp);
                }
            }

        }
    }

    for (int i = 0; i < n; i++) {
        puts(str[i]);
    }

    return 0;
}

// scanf_s("%d%*c", &n); --> gets랑 같이 사용시.
// scanf("%s", &name[i]);