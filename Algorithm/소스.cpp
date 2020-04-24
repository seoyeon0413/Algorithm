#include <stdio.h>
int sort[5000000];

void quickSort(int* data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while (i <= j)
    {
        while (data[key] >= data[i])
        {
            i++;
        }
        while (data[key] <= data[j] && j > start)
        {
            j--;
        }

        if (i >= j)
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void) {
    int arr[5000000];
    int n, k;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d ", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("%d", arr[k - 1]);
    // your code goes here
    return 0;
}