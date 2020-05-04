#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x)
{
	if (parent[x] == x)
		return x;

	return getParent(parent, parent[x]);
}

//각 부모 노드를 합칩니다.
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

//같은 부모 노드를 가지는지 확인
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b)
		return 1;
	else
		return 0;
}
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};
int main(void)
{
	int n = 7;
	int m = 11;

	vector <Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 27, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	//간선의 비용으로 오름차순 정렬
	sort(v.begin(), v.end());

	//각 정점이 포함된 그래프가 어디ㅣㄴ지 저장
	int parent[7];	//n
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//사이클이 발생하지 않는 경우 그래프에 포함
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);


	return 0;
}
/*
- 간선 숫자 = 노드 숫자  - 1
- 최소 비용 신장 트리에서는 사이클이 발생하면 안된다.
- 사이클 테이블에서 부모 노드가 같으면 사이클이 발생하는 것이기 때문에 무시.
*/