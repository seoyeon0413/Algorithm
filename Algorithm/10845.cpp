#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main()
{
    int n;
    int inputNum;
    char com[10];
    queue<int> s;


    scanf("%d", &n);

    while (n != 0) {
        scanf("%s", com);

        if (strcmp(com, "push") == 0) {
            scanf("%d", &inputNum);

            s.push(inputNum);
        }
        else if (strcmp(com, "pop") == 0) {
            if (!s.empty()) {
                cout << s.front() << endl;
                s.pop();
            }
            else {
                cout << -1 << endl;
            }

        }
        else if (strcmp(com, "size") == 0) {
            cout << s.size() << endl;
        }
        else if (strcmp(com, "empty") == 0) {
            cout << s.empty() << endl;
        }
        else if (strcmp(com, "front") == 0) {
            if (!s.empty()) {
                cout << s.front() << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else if (strcmp(com, "back") == 0) {
            if (!s.empty()) {
                cout << s.back() << endl;
            }
            else {
                cout << -1 << endl;
            }
        }

        n--;
    }



    return 0;
}