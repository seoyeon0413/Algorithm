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

/*
- 해밍거리 (Hamming distance)
모든 문자열을 한 자리씩 읽으면서 가장 많이 등장한(해밍 거리가 가장 짧은) 뭄자를 결과 문자열에 추가하면 됨.
*/
