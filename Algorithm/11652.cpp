#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int card[1000];
	int count[1000];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < n; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		count[card[i] - 1]++;
	}

	//sort(card, card + n);
	
	for (int i = 0; i < n; i++) {
		cout << count[i] << ' ';
	}

	for (int i = 0; i < n; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}
	

	return 0;
}
/*
5
1
3
1
3
1

0 -> 1 : 3
1 -> 2 : 2

*/