#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

stack<char> s;

bool check(string a)
{
	bool isInvalid = false;	//false¸é vps

	for (int i = 0; i < a.size(); i++) {
		char temp = a[i];
		if (temp == '(') {
			s.push(temp);
		}
		else {
			if (s.empty()) {	//vps X
				isInvalid = true;
				break;
			}
			else {
				s.pop();
			}
		}
	}

	while (!s.empty()) {
		isInvalid = true;
		s.pop();
	}

	return isInvalid;
}

int main(void)
{
	int t;
	string vps[100];

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> vps[i];
	}

	for (int i = 0; i < t; i++) {
		bool b = check(vps[i]);

		if (b) {
			cout << "NO" << endl;
		}
		else if (b && !s.empty()) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}

	return 0;
}