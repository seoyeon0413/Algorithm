#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int card[1000];
	int index[1000];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card, card + n);
	
	for (int i = 0; i < n; i++) {
		cout << card[i] << ' ';
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		if (card[i] != card[i + 1]) {
			index[j] = i;
			j++;
		}
	}

	for (int i = 0; i < j; i++) {
		if (i == 0) {
			index[i] = index[i] + 1;
		}
		else if (i == 1) {
			index[i] = index[i] - index[i - 1] + 1;
		}
		else {
			index[i] = index[i] - index[i - 1];
		}
	}

	cout << endl;
	for (int i = 0; i < j; i++) {
		cout << index[i] << ' ';
	}




	//2 5
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