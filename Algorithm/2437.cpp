#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];

int main()
{
	int n;
	int target = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	sort(d, d + n);

	for (int i = 0; i < n; i++) {
		if (target < d[i])
			break;
		target += d[i];
	}

	cout << target;

	return 0;
}
/*
- 전체 수 : 7+6+5+4+3+2+1

◆ 1 1 2 3 6 7 30
1 2 3 6 7 30
 = 
◆ 2 3 5 9 13 37
2 3 6 7 30
 = 
◆ 4 6 11 16 43
3 6 7 30
 =
◆ 7 12 18 46
6 7 30
 = 
◆ 13 19 48
7 30
 = 
◆ 20 49
30
 =
◆ 50
*/
/*
1				1
1+1				2
1+2				3
1+3				4
1+6				7
1+7				8
1+30			31

1+1+2			4
1+1+3			5
1+1+6			8
1+1+7			9
1+1+30			32

1+2+3			6
1+2+6			9
1+2+7			10
1+2+30			33

1+3+6			9
1+3+7			11
1+3+30			34
*/
