#include <stdio.h>

int d[1001];

int dp(int x)
{
	if (x == 0)
		return 1;	//왜 0일때 1이지...? 궁그매궁그매
	if (x == 1)
		return 0;
	if (x == 2)
		return 3;

	if (d[x] != 0)
		return d[x];

	int result = 3 * dp(x - 2);	//1번 부분
	for (int i = 4; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp(x - i);	//2번 부분
		}
	}


	return d[x] = result;

}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d", dp(n));


	return 0;
}

/*
d[n] = 3 * d[n-2] + (2 * d[n-4] + 2 * d[n-6] + ... + 2 * d[0])
		1번 부분			2번 부분
*/