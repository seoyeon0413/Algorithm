/*
[KMP(Knuth-Morris-Pratt)]
- 접두사, 접미사 : '반복되는 연산을 얼마나 줄일 수 있는지'
- 접두사와 접미사가 일치하는 최대 길이
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern)
{
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}

		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}

	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}

		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				printf("%d번째에서 찾았습니다.\n", i - patternSize + 2);
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	vector<int> table = makeTable(pattern);

	for (int i = 0; i < table.size(); i++) {
		cout << table[i] << ' ';
	}
	cout << endl;
	
	KMP(parent, pattern);


	return 0;
}
