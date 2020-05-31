#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, temp = "";
	int result = 0;
	bool minus = false;

	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (minus == true)
				result += -stoi(temp);
			else
				result += stoi(temp);

			temp = "";
			
			if (s[i] == '-') {
				minus = true;
				continue;
			}

		}

		temp += s[i];
	}

	cout << result;

	return 0;
}
/*
◆ 마이너스가 한번이라도 등장한 시점
-> 그 뒤로 이어딘 모든 숫자들은 그 부호에
상관없이 모두 마이너스로 처리할 수 있다는 특징

◆ stoi = string to int
*/
