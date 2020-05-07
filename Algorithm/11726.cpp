#include <stdio.h>

int d[1001];

int dp(int x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;

	if (d[x] != 0)
		return d[x];

	return d[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main()
{
	int n;
	
	scanf("%d", &n);

	printf("%d", dp(n));


	return 0;
}


/*
x -> 경우의 수
1 -> 1
2 -> 2
3 -> 3
규칙성을 찾아서 점화식을 만든다.
--------------------------------
n: (n-1) + 1 -> 1가지
n: (n-2) + 2 -> 1가지 (앞에거 포함해서 1개임.)

-> d(n) = d(n-1) + d(n-2)

n: (n-3) + 3 -> 이미 처리를 한 모양 중 하나이기 때문에 (n-1), (n-2)만 고려.
*/