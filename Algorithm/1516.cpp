#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 501

using namespace std;

int time[MAX], inDegree[MAX], result[MAX];
vector<int> va[MAX];
queue<int> q;

void topologySort(int n)
{
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			break;
		}

		int x = q.front();
		q.pop();

		for (int j = 0; j < va[x].size(); j++) {
			int y = va[x][j];
			
			result[y] = max(result[y], result[x] + time[y]);

			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << endl;
	}

}

int main()
{
	int n;
	int buildN;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];

		while (1) {
			cin >> buildN;

			if (buildN == -1)
				break;

			va[buildN].push_back(i);
			inDegree[i]++;
		}
	}

	topologySort(n);

	return 0;
}
