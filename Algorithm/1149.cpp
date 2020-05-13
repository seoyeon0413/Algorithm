#include <iostream>
#include <algorithm>

using namespace std;

typedef struct RGB {
	int r;
	int g;
	int b;
} RGB;

int N;
RGB rgb[1001];
int selected[1001];
int result = 0;

int check(int min, int i)
{
	if (min == rgb[i].r)
		return 0;
	if (min == rgb[i].g)
		return 1;
	if (min == rgb[i].b)
		return 2;
}

int minRGB(int i, int n, int start)
{
	
	
	/*
	int min = 10000;

	if (i == 0 && start == 1) {
		selected[i] = 1;
		return result += rgb[i].r;
	}
	if (i == 0 && start == 2) {
		selected[i] = 2;
		return result += rgb[i].g;
	}
	if (i == 0 && start == 3) {
		selected[i] = 3;
		return result += rgb[i].b;
	}


	if ((rgb[i].r <= rgb[i].g) && (rgb[i].r <= rgb[i].b) && selected[i - 1] != 1) {
		min = rgb[i].r;
		selected[i] = 1;
	}
	if ((rgb[i].g <= rgb[i].r) && (rgb[i].g <= rgb[i].b) && selected[i - 1] != 2) {
		min = rgb[i].g;
		selected[i] = 2;
	}
	if ((rgb[i].b <= rgb[i].r) && (rgb[i].b <= rgb[i].g) && selected[i - 1] != 3) {
		min = rgb[i].b;
		selected[i] = 3;
	}

	if (i == N - 1)
		result = 0;

	return result += minRGB(i++, n++, start);
	*/
	/*
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if ((rgb[i].r < rgb[i].g) && (rgb[i].r < rgb[i].b)) {

			}
			selected[i] = check(m, i);
		}
		else {
			if (selected[i - 1] == 0) {
				m = min(rgb[i].g, rgb[i].b);
				selected[i] = check(m, i);
			}
			if (selected[i - 1] == 1) {
				m = min(rgb[i].r, rgb[i].b);
				selected[i] = check(m, i);
			}
			if (selected[i - 1] == 2) {
				m = min(rgb[i].r, rgb[i].g);
				selected[i] = check(m, i);
			}
		}

		// 26, 57, 13 -> 96

		result += m;
		//cout << 's' << selected[i] << endl;
		//cout << m << endl;
	}

	return result;
	*/
}

int main()
{	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> rgb[i].r >> rgb[i].g >> rgb[i].b;
	}

	cout << min(minRGB(0, 0, 2), min(minRGB(0, 0, 0), minRGB(0, 0, 1)));

	return 0;
}