#include <iostream>

using namespace std;

int main()
{
	int num;

	cin >> num;

	int array[1000] = {0};
	for (int i = 0; i < num; i++) {
		cin >> array[i];
	}

	//selection sort
	int index, min;
	for (int i = 0; i < num; i++) {
		min = 9999;
		for (int j = i; j < num; j++) {
			if (array[j] < min) {
				min = array[j];
				index = j;
			}

			int temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
	}


	//bubble sort
	/*
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	*/

	for (int i = 0; i < num; i++)
	{
		cout << array[i] << endl;
	}

	return 0;
}