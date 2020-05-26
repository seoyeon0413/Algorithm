#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#define MAX 1001

using namespace std;

typedef struct coordinate {
	int x;
	int y;
} C;

int getParent(int set[], int x)
{
	if (set[x] == x)
		return x;

	return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}

int find(int set[], int a, int b)
{
	a = getParent(set, a);
	b = getParent(set, b);

	if (a == b)
		return 1;
	else
		return 0;
}

double getDistance(C a, C b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

class Edge {
public:
	int node[2];
	double distance;

	Edge(int a, int b, float distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main()
{
	int n, m;
	int node1[MAX], node2[MAX];
	vector<Edge> v;
	C star[MAX];

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> star[i].x >> star[i].y;
	}
	for (int i = 0; i < m; i++) {
		cin >> node1[i] >> node2[i];
	}

	int set[MAX];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	//연결된 통로 미리 제외하기
	for (int i = 0; i < m; i++) {
		unionParent(set, node1[i] - 1, node2[i] - 1);
	}

	//모두 연결
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			v.push_back(Edge(i + 1, j + 1, getDistance(star[i], star[j])));
		}
	}

	sort(v.begin(), v.end());

	float sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%.2lf", sum);


	return 0;
}
