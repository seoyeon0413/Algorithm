#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int node, e;
int INF = 1000000000;

vector<pair<int, int>> a[200001];
int d[200001];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> pq; //힙구조 큰 순서부터 맨 앞에 있음 
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        //v[current] = 1;

        if (d[current] < distance) continue; //최단 거리가 아닌 경우 스킵 

        for (int i = 0; i < a[current].size(); i++)
        {
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;

            if (d[next] > nextDistance)
            {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }


    }
}

int main()
{

    cin >> node >> e;

    for (int i = 1; i <= node; i++)
        d[i] = INF;

    int start;
    cin >> start;

    int u, v, w;

    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        a[u].push_back(make_pair(v, w));
    }


    dijkstra(start);

    for (int i = 1; i <= node; i++)
    {
        if (d[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", d[i]);

    }

    return 0;
}