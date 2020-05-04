#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

stack<char> s;
int checkGoodWord(string str) {
	int check = 0;	//맞으면 1, 틀리면 0

	if (str[0] == 'A') {
		s.push('A');
	}

	return check;
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



	return 0;
}