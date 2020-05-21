#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

bool check[1000001];

int getParent(int set[], int x)
{
	if (set[x] == x)
		return x;

	return getParent(set, set[x]);
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

class Edge {
public:
	int node[2];
	int distance;

	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge &e) {
		return this->distance < e.distance;
	};
};

int main()
{
	int n, m;
	vector<Edge> v;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v.push_back(Edge(a, b, d));
	}

	sort(v.begin(), v.end());

	int set[MAX];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			check[i] = true;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	//연결된 간선들 중에서 가장 큰 간선을 제외함.
	//정렬이 되어있기 때문에 마지막걸 빼주면 됨.
	for (int i = v.size() - 1; i >= 0; i--) {
		if (check[i] == true) {
			sum -= v[i].distance;
			break;
		}
	}

	cout << sum;

	return 0;
}
