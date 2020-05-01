#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int map[100][100];

void setWall()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) {
				if (map[i][j + 1] == 0)
					map[i][j + 1] = 1;
				else if (map[i][j + 1] == 2)
					continue;

				if (map[i + 1][j] == 0)
					map[i + 1][j] = 1;
				else if (map[i + 1][j] == 2)
					continue;
				if (i - 1 < 0) {
					continue;

					if (map[i - 1][j] == 0)
						map[i - 1][j] = 1;
					else if (map[i - 1][j] == 2)
						continue;
				}
				if (j - 1 < 0) {
					continue;

					if (map[i][j - 1] == 0)
						map[i][j - 1] = 1;
					else if (map[i][j - 1] == 2)
						continue;
				}
			}
		}
	}
}

int main()
{
	int result = 0;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	setWall();
	
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}



	return 0;
}