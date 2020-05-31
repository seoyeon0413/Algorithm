#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> a;

int getNum(int num, vector<pair<int, int>> va)
{
	int result = 0;
	int min = 100001;
	/*
1 4
2 3
3 2
4 1
5 5

1 4
2 5
3 6
4 2
5 7
6 1
7 3
	*/
	
	sort(va.begin(), va.end());
	/*
	for (int i = 0; i < num; i++) {
		if (min > va[i].second) {
			min = va[i].second;
			result++;
		}
	}
	*/
	
	int c = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (va[i].second > va[j].second) {
					c = 1;
					break;
			}
		}

		if (c == 0)
			result++;
		else
			c = 0;
	}
	
	return result;
}

int main()
{
	int t, n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x, y;
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		cout << getNum(n, a) << endl;
		a.clear();
	}


	return 0;
}
