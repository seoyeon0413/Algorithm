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
n: (n-1) + 1 -> 1����
n: (n-2) + 2 -> 2���� (�տ��� ����)

-> d(n) = d(n-1) + 2* d(n-2)

n: (n-3) + 3 -> �̹� ó���� �� ��� �� �ϳ��̱� ������ (n-1), (n-2)�� ���.
*/