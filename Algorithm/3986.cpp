#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int checkGoodWord(string str) {
	//맞으면 1, 틀리면 0
	stack<char> s;

	if ((str.size() % 2) != 0) {	//길이가 홀수면 바로 틀림
		return 0;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (s.empty()) {	//stack이 비어있으면 무조건 push
				s.push(str[i]);
				//cout << str[i] << endl;
				continue;
			}
			else {
				if (str[i] != s.top()) {	//다르면
					s.push(str[i]);
					//cout << "다르면: " << str[i] << endl;
				}
				else {	//같으면
					s.pop();
				}
			}
		}

		if (s.empty()) {	//비어있으면
			return 1;
		}
		else {	//비어있지 않으면
			return 0;
		}
	}
	
}
int main()
{
	int n;
	int result = 0;
	string str[101];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
		result += checkGoodWord(str[i]);
	}

	cout << result;

	return 0;
}