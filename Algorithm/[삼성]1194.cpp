#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct set {
	int y, x, k, result;
};

int yp, xp;
int n, m;
char map[51][51];
bool visited[51][51][64];
int dx[4] = { +1, -1, 0, 0 };	// 동,서
int dy[4] = { 0, 0, +1, -1 };	// 남,북

// 열쇠를 가지고 있는지 확인
bool check_key(int cur_key, char door)
{
	if ((cur_key & (1 << (door - 'A'))) == 0)
		return false;
	return true; 
}

// 열쇠를 집으면 실행
int set_key(int cur_key, char value)
{
	return cur_key | (1 << (value - 'a'));
}

int bfs()
{
	queue<set> q;

	q.push({yp, xp, 0, 0});
	visited[yp][xp][0] = true;

	while (!q.empty()) {
		struct set s = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = s.y + dy[i];
			int nx = s.x + dx[i];

			if ((ny < 0 || ny >= n || nx < 0 || nx >= m) || visited[ny][nx][s.k] || map[ny][nx] == '#')	// 넘어가는 경우
				continue;

			// 문을 만난 경우
			if (map[ny][nx] >= 'A' && map[ny][nx] <= 'F') {
				// 해당 문에 맞는 열쇠가 있는지 확인
				if (check_key(s.k, map[ny][nx])) {
					q.push({ ny, nx, s.k, s.result + 1 });
					visited[ny][nx][s.k] = true;
				}
			}
			// 열쇠를 집는 경우
			else if (map[ny][nx] >= 'a' && map[ny][nx] <= 'f') {
				int key = set_key(s.k, map[ny][nx]);
				q.push({ ny, nx, key, s.result + 1 });
				visited[ny][nx][s.k] = true;
			}
			// 목적지에 도착한 경우
			else if (map[ny][nx] == '1')
				return s.result + 1;
			else {
				q.push({ ny, nx, s.k, s.result + 1 });
				visited[ny][nx][s.k] = true;
			}
			
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == '0') {
				yp = i;
				xp = j;
			}
		}
	}

	cout << bfs() << endl;

	return 0;
}
/*
빈곳(.), 열쇠(a-f) -> 언제나 이동 가능
벽(#)
문(A-F) -> 열쇠필요
0 - 출발 = 빈곳
1 - 도착

- 출력: 미로를 탈출하는데 걸리는 이동 횟수의 최솟값
만약 민식이가 미로를 탈출 할 수 없으면, -1을 출력
*/
