#include <math.h>
#include <iostream>

using namespace std;

void main()
{
	int num = 2143;

	int k = 1;
	int digit = 1;

	cout<< "- Number: " << num <<endl;


	/*digit*/
	while (1) {
		if ((num / k) < 10)
		{
			break;
		}
		else {
			digit = digit + 1;
			k *= 10;
		}
	}
	
	//2*1000 + 1*100 + 4*10 + 3*1
	//3*1000 + 4*100 + 1*10 + 2*1
	int newNum = 0;
	for (int i = 0; i < digit; i++) {
		int n = (int)(num / pow(10, i)) % 10;
		//cout << n;
		newNum = newNum + (n * pow(10, digit-i-1));
	}

	cout << "\n[Result]" << endl;
	cout << newNum << endl;

	
}

/*
[�������]
1. % -> int���� ���ؼ��� ��� ����.
2. �ڸ��� ���ϱ�
	: 10���� ������ ���� ���� 10���� ���� ��찡 �ִ� �ڸ���
3. ���� ������
	: �ڸ��� ������ ���� �ϱ� ((num / pow(10,i)) % 10 ) => �Ųٷ� ����.
*/