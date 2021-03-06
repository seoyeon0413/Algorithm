#include <stdio.h>

int d[1001];

int dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 3;

	if (d[x] != 0)
		return d[x];

	return d[x] = (dp(x - 1) + 2 * dp(x - 2)) % 10007;
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d", dp(n));


	return 0;
}


/*
n: (n-1) + 1 -> 1가지
n: (n-2) + 2 -> 2가지 (앞에거 제외)

-> d(n) = d(n-1) + 2* d(n-2)

n: (n-3) + 3 -> 이미 처리를 한 모양 중 하나이기 때문에 (n-1), (n-2)만 고려.
*/