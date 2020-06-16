#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[21][21];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (t[i][k] == -1 || t[k][j] == -1 || t[i][j] == -1)
					continue;
				if (i != k && j != k && i != j) {
					if (t[i][j] == t[i][k] + t[k][j]) {
						t[i][j] = -1;
					}
					else if (t[i][j] > t[i][k] + t[k][j] && t[i][j] != -1) {
						cout << -1;
						return 0;
					}
				}
			}
		}
	}
	
	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i][j] != -1) {
				r += t[i][j];
			}
		}
	}

	cout << r;

	return 0;
}
