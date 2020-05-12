#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int input[501] = { 0 };
	int temp[501] = { 0 };
	int sum[501] = { 0 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> input[j];

			if(j == 0)
				sum[j] += input[j];
			else
				sum[j] = input[j] + max(temp[j], temp[j - 1]);
		}

		for (int k = 0; k < i + 1; k++) {
			temp[k] = sum[k];
		}
	}

	int result = sum[0];
	for (int i = 0; i < n; i++) {
		if (result < sum[i])
			result = sum[i];
	}

	cout << result;

	return 0;
}