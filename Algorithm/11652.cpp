#include<stdio.h>
#include<algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    long long int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    sort(arr, arr + n);

    int maxIndex = 0;
    int maxCount = 1;
    int curCount = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            curCount++;
        }
        else {
            curCount = 1;
        }
        if (curCount > maxCount) {
            maxCount = curCount;
            maxIndex = i;
        }
    }
    printf("%lld ", arr[maxIndex]);

    return 0;
}