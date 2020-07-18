#include <iostream>
#include <vector>

using namespace std;

int min = 9999;
int n, m;
char map[51][51];
int dx[4] = { +1, -1, 0, 0 };	// 동,서
int dy[4] = { 0, 0, +1, -1 };	// 남,북

void dfs(int yp, int xp, vector<char> key, int result)
{
	for (int i = 0; i < 4; i++) {
		if (yp + dy[i] < 0 || yp + dy[i] >= n || xp + dx[i] < 0 || xp + dx[i] >= m)	// 범위 벗어날 경우 return
			return;

		if (map[yp + dy[i]][xp + dx[i]] != '#') {
			if (map[yp + dy[i]][xp + dx[i]] == '1') {	// 도착할 때, 끝!
				result++;
				if (result <= min) {
					min = result;
				}
				cout << "- min:" << min << endl;
				return;
			}
			else if (map[yp + dy[i]][xp + dx[i]] == '0') {	// 도착할 때, 끝!
				result++;
				cout << "출발지" << result << endl;
				dfs(yp - dy[i], xp - dx[i], key, result);
			}
			else if (map[yp + dy[i]][xp + dx[i]] == '.') {
				result++;
				cout << "."<< result << endl;
				dfs(yp + dy[i], xp + dx[i], key, result);
			}
			else if (map[yp + dy[i]][xp + dx[i]] >= 'a' && map[yp + dy[i]][xp + dx[i]] >= 'f') {
				key.push_back(map[yp + dy[i]][xp + dx[i]]);
				result++;
				cout << "af" << result << endl;
				dfs(yp + dy[i], xp + dx[i], key, result);
			}
			else if (map[yp + dy[i]][xp + dx[i]] >= 'A' && map[yp + dy[i]][xp + dx[i]] >= 'F') {
				if (find(key.begin(), key.end(), map[yp + dy[i]][xp + dx[i]]) == key.end()) {	// 열쇠가 없으면,
					result++;
					cout << "AF없" << result << endl;
					dfs(yp - dy[i], xp - dx[i], key, result);
				}
				else {	// 열쇠가 있으면,
					result++;
					cout << "AF있" << result << endl;
					dfs(yp + dy[i], xp + dx[i], key, result);
				}
			}
		}
	}
}

int main()
{
	int positionX, positionY;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == '0') {
				positionY = i;
				positionX = j;
			}
		}
	}

	vector<char> key;
	dfs(positionY, positionX, key, 0);

	if (min == 0) {
		cout << -1;
		return -1;
	}

	cout << min;

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
