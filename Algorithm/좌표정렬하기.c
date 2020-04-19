#include <stdio.h>
typedef struct coordinate {
	int x;
	int y;
}cd;
int main(void)
{
	int n;
	cd xy[10000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &xy[i].x, &xy[i].y);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (xy[j].x > xy[j + 1].x) {
				cd temp = xy[j];
				xy[j] = xy[j + 1];
				xy[j + 1] = temp;
			}
			else if (xy[j].x == xy[j + 1].x) {
				if (xy[j].y > xy[j + 1].y) {
					cd temp = xy[j];
					xy[j] = xy[j + 1];
					xy[j + 1] = temp;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", xy[i].x, xy[i].y);
	}

	return 0;
}