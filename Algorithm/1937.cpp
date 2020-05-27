#include <iostream>

using namespace std;

int bambooGrove[501][501];
int n;
int newDays = 0;

int daysToLive(int i, int j, int days)
{
	int check = 0;
	
	while (check != -1) {
		if (bambooGrove[i - 1][j] > bambooGrove[i][j]) {
			check = 1;
			cout << "- check: " << check << endl;
			++newDays = daysToLive(i, ++j, ++days);
		}
		if (bambooGrove[i][j - 1] > bambooGrove[i][j]) {
			check = 2;
			cout << "- check: " << check << endl;
			++newDays = daysToLive(i, ++j, ++days);
		}
		if (bambooGrove[i][j + 1] > bambooGrove[i][j]) {
			check = 3;
			cout << "- check: " << check << endl;
			++newDays = daysToLive(i, ++j, ++days);
		}
		if (bambooGrove[i + 1][j] > bambooGrove[i][j]) {
			check = 4;
			cout << "- check: " << check << endl;
			++newDays = daysToLive(i, ++j, ++days);
		}

		if (check != 1 || check != 2 || check != 3 || check != 4 || check == 0) {
			check = -1;
			cout << 'c' << check << endl;
		}

		cout << newDays << endl;
	}


	return newDays;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> bambooGrove[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cout << "(" << i << ", " << j << ")" << endl;

			int r = daysToLive(i, j, 1);
			newDays = 0;
			if(r > max)
				max = r;
		}
	}

	cout << max;


	return 0;
}
