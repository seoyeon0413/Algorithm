/*
<다익스트라 알고리즘>
: 최단 경로 탐색 알고리즘
- 음의 간선 포함할 수 없음.

: 다이나믹 프로그래밍 or 그리디 알고리즘 -> (dynamic: 최단 거리는 여러 개의 최단 거리로 이루어져 있기 때문)
- 하나의 최단 거리를 구할 때 그 이전까지 구했던 최단 거리 정보를 그대로 사용한다는 특징.
- 2D array 사용
*/
#include <iostream>
#include <vector>
#include <queue>	//우선순위 큐 -> '힙'과 같은 방식

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int>> a[7];	//간선 정보
int d[7];	//최소 비용

void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int>> pq;	//힙 구조 입니다.
	
	//가까운 순서대로 처리하므로 큐를 사용합니다.
	while (!pq.empty()) {
		int current = pq.top().first;
		//짧은 것이 먼저 오도록 음수화(-)합니다.
		int distance = -pq.top().second;
		pq.pop();
		//최단 거리가 아닌 경우 스킵합니다.
		if (d[current] < distance)
			continue;
		for (int i = 0; i < a[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = a[current][i].first;
			//선택된 노드를 인접 노드로 거쳐서 가는 비용
			int nextDistance = distance + a[current][i].second;
			//기존의 최소 비용보다 더 저렴하다면 교체합니다.
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main()
{
	//기본적으로 연결되지 않은 경우 비용은 무한입니다.
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}

	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);

	//결과를 출력합니다.
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}

	return 0;
}
/*
#include <stdio.h>

int number = 6;
int INF = 1000000000;

//전체 그래프를 초기화합니다.
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};
bool v[6];	//visited - 방문한 노드
int d[6];	//최단거리

//가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex()
{
	int min = INF;
	int index = 0;

	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}

	return index;
}
//다익스트라를 수행하는 함수
void dijkstra(int start)
{
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}

	v[start] = true;

	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		v[current] = true;

		for (int j = 0; j < 6; j++) {
			if (!v[j]) {
				if (d[current] + a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main()
{
	dijkstra(0);

	for (int i = 0; i < number; i++) {
		printf("%d ", d[i]);
	}


	return 0;
}
*/