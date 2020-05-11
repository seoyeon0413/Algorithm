#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int temp[501] = { 0 };
	int sum[501] = { 0 };
	int fValue = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> temp[j];
			

			sum[j] = temp[j] + max(sum[j], sum[j - 1]);


			cout << sum[j] << ' ';
		}
		cout << endl;
	}


	return 0;
}