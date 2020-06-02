#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s[1001];
	string result = "";
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n);
	
	int a = 0, t = 0, g = 0, c = 0;
	char maxElement = ' ';
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[j][i] == 'A') {
				a++;
			}
			if (s[j][i] == 'T') {
				t++;
			}
			if (s[j][i] == 'G') {
				g++;
			}
			if (s[j][i] == 'C') {
				c++;
			}
		}

		if (a >= t && a >= g && a >= c)
			maxElement = 'A';
		else if (c >= a && c >= t && c >= g)
			maxElement = 'C';
		else if (g >= a && g >= c && g >= t)
			maxElement = 'G';
		else if (t >= a && t >= c && t >= g)
			maxElement = 'T';

		result.push_back(maxElement);

		a = 0; t = 0; g = 0; c = 0;
	}

	int r = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] != result[j])
				r++;
		}
	}

	cout << result << endl;
	cout << r;

	return 0;
}
