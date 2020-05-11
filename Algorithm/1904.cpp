#include <stdio.h>

int d[1000001];

int dp(int x)
{
	if (x == 0)	//x
		return 1;
	if (x == 1)	//1
		return 1;
	if (x == 2)	//00, 11
		return 2;
	if (x == 3)	//100, 001, 111
		return 3;
	if (x == 4)	//1100, 0011, 1001, 1111, 0000
		return 5;
	if (x == 5)	//00111, 10011, 11001, 11100, 11111, 00001, 10000
		return 8;

	if (d[x] != 0)
		return d[x];
	
	return d[x] = (dp(x - 1) + dp(x - 2)) % 15746;
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d", dp(n));


	return 0;
}

//fibonacci ¹®Á¦