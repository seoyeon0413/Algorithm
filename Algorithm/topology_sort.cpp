/*
● 위상 정렬(Topology sort)
- 순서가 정해져있는 작업
- DAG(Directed Acyclic Gragh)
- 사이클이 발생할 경우 위상 정렬을 수행할 수 없음. (시작점이 없어서)
- 현재 그래프가 위상정렬이 가능한지 -> 가능하다면 결과는?
- Stack 아니면 Queue -> 'Queue'
- 진입차수: 특정한 노드가 있을 때, 이 노드로 들어오는 개수.
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX]; //inDegree -> 진입차수
vector<int> a[MAX];

void topologySort()
{
	int result[MAX];
	queue<int> q;

	//진입 차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
	for (int i = 1; i <= n; i++) {
		//n개를 방문하기 전에 큐가 비어버리면 사이클이 발생한 것입니다.
		if (q.empty()) {
			printf("사이클이 발생했습니다.");
			return;
		}

		int x = q.front();
		q.pop();
		result[i] = x;

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	//결과
	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main()
{
	n = 7;

	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();


	return 0;
}