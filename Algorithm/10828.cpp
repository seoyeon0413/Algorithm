#include <iostream>
#include <stack>
#include<string.h>

using namespace std;

int main()
{
    int n;
    int inputNum;
    char com[10];
    stack<int> s;


    scanf("%d", &n);

    while (n != 0) {
        scanf("%s", com);

        if (strcmp(com, "push") == 0) {
            scanf("%d", &inputNum);

            s.push(inputNum);
        }
        else if (strcmp(com, "pop") == 0) {
            if (!s.empty()) {
                cout << s.top() << endl;
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
            if (!s.empty()) {
                cout << 0 << endl;
            }
            else {
                cout << 1 << endl;
            }
        }
        else if (strcmp(com, "top") == 0) {
            if (!s.empty()) {
                cout << s.top() << endl;
            }
            else {
                cout << -1 << endl;
            }
        }

        n--;
    }



    return 0;
}