#include <iostream>

using namespace std;

int n, m;
int x, y;
int k;
int map[21][21];
int dice[6];
const int dy[] = { 0,0,-1,+1 };	// 동 서 남 북
const int dx[] = { +1,-1,0,0 };

void move_dice(int dir)
{
	int ndice[6];

	switch (dir) {
    case 0:
        ndice[0] = dice[0];
        ndice[5] = dice[1];
        ndice[2] = dice[2];
        ndice[4] = dice[3];
        ndice[1] = dice[4];
        ndice[3] = dice[5];
        break;
    case 1:
        ndice[0] = dice[0];
        ndice[4] = dice[1];
        ndice[2] = dice[2];
        ndice[5] = dice[3];
        ndice[3] = dice[4];
        ndice[1] = dice[5];
        break;
    case 2:
        ndice[3] = dice[0];
        ndice[0] = dice[1];
        ndice[1] = dice[2];
        ndice[2] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;
    case 3:
        ndice[1] = dice[0];
        ndice[2] = dice[1];
        ndice[3] = dice[2];
        ndice[0] = dice[3];
        ndice[4] = dice[4];
        ndice[5] = dice[5];
        break;
    default:
        break;
	}

    for (int i = 0; i < 6; i++) {
        dice[i] = ndice[i];
    }
}

int main()
{
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int dir;
	for (int i = 0; i < k; i++) {
		cin >> dir;
        dir--;
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            continue;

        move_dice(dir);

        if (map[ny][nx] == 0)
            map[ny][nx] = dice[3];
        else {
            dice[3] = map[ny][nx];
            map[ny][nx] = 0;
        }

        y = ny;
        x = nx;

        cout << dice[1] << endl;
	}


	return 0;
}
/*
(r,c) -> r: '북쪽'으로부터 떨어진 칸의 개수
	  -> c: '서'쪽으로부터 떨어진 칸의 개수
(x,y) -> 놓여져 있는 곳의 좌표

지도 칸 = 0, 주사위 바닥면 = 칸
지도 칸 != 0, 칸 -> 주사위의 바닥면으로 복사, 칸에 쓰여있는 수 = 0

상단에 쓰여 있는 값 출력.
넘어갈 경우, 출력도 X.

- 복사: 바닥면, 출력: 윗면
*/

