#include <iostream>
#include <vector>
#include <queue>
#define MAX 32100

using namespace std;

int inDegree[MAX]; //inDegree -> 진입차수
vector<int> va[MAX];

void topologySort(int n)
{
	int result[MAX];
	queue<int> q;

	//진입차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < va[x].size(); j++) {
			int y = va[x][j];

			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << ' ';
	}
}

int main()
{
	int n, m;
	int a, b;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		va[a].push_back(b);
		inDegree[b]++;
	}

	topologySort(n);

	return 0;
}
