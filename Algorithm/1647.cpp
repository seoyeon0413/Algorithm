#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001

using namespace std;

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

int checkSet(int set[], int n)
{
	int a = set[0];
	int b = a;
	int check = 0;
	for (int i = 0; i < n; i++) {
		b = set[i];
		if (a != b) {
			check++;
		}
	}

	if (check == 2)	//3개그룹 이상
		return 1;
	else //2개그룹
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
	int set[MAX];
	vector<Edge> v;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v.push_back(Edge(a, b, d));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		set[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		//if (v[i].node[0] == v[v.size()-1].node[0] || v[i].node[1] == v[v.size() - 1].node[0] || v[i].node[0] == v[v.size() - 1].node[1] || v[i].node[1] == v[v.size() - 1].node[1])
		//	continue;

		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
			cout << checkSet(set, n) << endl;
		}
	}

	cout << sum;

	return 0;
}
