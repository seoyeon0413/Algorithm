#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check[30][30];

bool checkCheck(int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == 1) {
                return false;
            }
        }
    }
    // 모두 0일 경우, return true
    return true;
}

void initCheck(int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = 0;
        }
    }
}

void erase(vector<string> b, int i, int j)
{
    if (b[i][j] == b[i][j + 1]) {
        if (b[i][j] == b[i + 1][j + 1]) {
            if (b[i][j] == b[i + 1][j]) {
                check[i][j] = 1;
                check[i][j + 1] = 1;
                check[i + 1][j + 1] = 1;
                check[i + 1][j] = 1;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        cout << "[board]" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        // answer 구하기
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j] == 1)
                    answer++;
            }
        }
        // array check 0으로 초기화
        initCheck(m, n);
        // 지워져야할 것들 체크
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == 'Z')
                    continue;

                erase(board, i, j);
            }
        }

        if (checkCheck(m, n)) {
            break;
        }

        // column마다 지워질게 몇 개인지 세기
        int j = 0;
        for (int i = 0; i < n; i++) {
            int checkTrue = 0, checkFalse = 0;
            for (j = 0; j < m; j++) {
                if (check[j][i] == 0)
                    checkFalse++;
                else
                    checkTrue++;

                // 지워내고 내려오게만들기
                if (check[j][i] == 1 && check[j + 1][i] == 0) {
                    for (int k = 0; k < checkFalse; k++) {
                        board[j - k][i] = board[j - checkTrue - k][i];
                    }
                }
            }

            for (int k = 0; k < checkTrue; k++) {
                board[k][i] = 'Z';
            }

        }
    }

    return answer;
}

int main()
{
    int m = 4, n = 5;
    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    cout << solution(m, n, board) << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            check[i][j] = 0;
        }
    }

    m = 6; n = 6;
    board = { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" };
    cout << solution(m, n, board) << endl;

    return 0;
}
