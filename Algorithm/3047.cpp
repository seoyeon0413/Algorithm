#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n[3];
	char alpha[3];

	for (int i = 0; i < 3; i++) {
		cin >> n[i];
	}

	for (int i = 0; i < 3; i++) {
		cin >> alpha[i];
	}

	sort(n, n+3);

	for (int i = 0; i < 3; i++) {
		if (alpha[i] == 'A') {
			cout << n[0] << ' ';
		}
		else if (alpha[i] == 'B') {
			cout << n[1] << ' ';
		}
		else {
			cout << n[2] << ' ';
		}
	}


	return 0;
}