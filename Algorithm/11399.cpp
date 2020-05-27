#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
	int n;
	int stay[1001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stay[i];
	}

	sort(stay, stay + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			arr[i] += stay[j];
		}
	}

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += arr[i];
	}

	cout << result;

	return 0;
}
/*
3 1 4 3 2

1 2 3 3 4
 = 1
1+2 = 3
1+2+3 = 6
1+2+3+3 = 9
1+2+3+3+4 = 13

1+3+6+9+13 = 32
*/
