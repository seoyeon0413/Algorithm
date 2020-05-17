#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

class Edge {
public:
	int node;
	int time;
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];	//임계경로 변수
vector<Edge> a[MAX];	//정방향
vector<Edge> b[MAX];	//역방향: 역추적을 위해 사용

void topologySort()
{
	queue<int> q;
	//시작점 노드를 큐에 삽입합니다.
	q.push(start);
	//더이상 방문할 노드가 없을 때까지
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {
			Edge y = Edge(a[x][i].node, a[x][i].time);
			if (result[y.node] <= y.time + result[x]) {
				result[y.node] = y.time + result[x];
			}
			//새롭게 진입차수가 0이된 정점을 큐에 삽입
			if (--inDegree[y.node] == 0) {
				q.push(y.node);
			}
		}
	}

	//결과를 역추적
	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = Edge(b[y][i].node, b[y][i].time);
			//최장 경로에 포함되는 간선인지 확인
			if (result[y] - result[x.node] == x.time) {
				count++;

				//큐에 한 번씩만 담아 추적합니다.
				if (c[x.node] == 0) {
					q.push(x.node);
					c[x.node] = 1;
				}
			}
		}
	}

	cout << result[finish] << endl << count;
}

int main()
{
	int m;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, node, time;

		cin >> x >> node >> time;
		a[x].push_back(Edge(node, time));
		inDegree[node]++;
		b[node].push_back(Edge(x, time));
	}
	cin >> start >> finish;

	topologySort();

	return 0;
}
