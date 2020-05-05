#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int checkGoodWord(string str) {
	//������ 1, Ʋ���� 0
	stack<char> s;

	if ((str.size() % 2) != 0) {	//���̰� Ȧ���� �ٷ� Ʋ��
		return 0;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (s.empty()) {	//stack�� ��������� ������ push
				s.push(str[i]);
				//cout << str[i] << endl;
				continue;
			}
			else {
				if (str[i] != s.top()) {	//�ٸ���
					s.push(str[i]);
					//cout << "�ٸ���: " << str[i] << endl;
				}
				else {	//������
					s.pop();
				}
			}
		}

		if (s.empty()) {	//���������
			return 1;
		}
		else {	//������� ������
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