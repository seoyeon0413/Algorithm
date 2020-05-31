#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

int main()
{
	string n;
	bool check = false;
	int result = 0;
	cin >> n;

	int num = 0;
	for (int i = 0; i < n.size(); i++) {
		num += (n[i] - '0');

		if (n[i] - '0' == 0) {
			check = true;
		}
	}

	if (num % 3 != 0 || check == false) {
		result = -1;
		cout << result;
	}

	if (num % 3 == 0 && check == true) {
		for (int i = 0; i < n.size(); i++) {
			a.push_back(n[i] - '0');
		}
	}

	sort(a.begin(), a.end());

	for (int i = a.size() - 1; i >= 0; i--) {
		cout << a[i];
	}

	return 0;
}
/*
◆ 각 숫자 자릿수의 합이 3의 배수라면,
전체 숫자는 항상 3의 배수가 된다.

=> 각 숫자 자릿수의 합이 3의 배수인지 확인
 + '0이 포함되어 있는 경우'에 한해서 큰 숫자 순서대로 출력
*/

#include <iostream>

using namespace std;

int number[10];	//0~9까지의 숫자가 몇개인지

int main()
{
	string a;
	int temp = 0;	//3의배수인지 확인

	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		number[a[i] - '0']++;
		temp += a[i] - '0';
	}

	if (temp % 3 == 0 && number[0] != 0) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < number[i]; j++) {
				cout << i;
			}
		}
	}
	else {
		cout << -1;
	}


	return 0;
}
