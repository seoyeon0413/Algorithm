#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
string num;
vector<char> result;

int main()
{
	cin >> n >> k;
	cin >> num;

	int i = 0;
	while (i != num.size()) {
		while (k != 0 && !result.empty() && result.back() < num[i]) {
			result.pop_back();
			k--;
		}

		result.push_back(num[i]);
		i++;
	}

	while (k--) {
		result.pop_back();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}



	return 0;
}
