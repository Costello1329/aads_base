#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
	size_t arraySize;
	cin >> arraySize;

	vector<size_t> array(arraySize);
	array.reserve(arraySize);

	for (size_t &num: array)
		cin >> num;

	size_t comparableNumber;
	cin >> comparableNumber;

	size_t counter = 0;

	for (const size_t &num: array)
		if (num == comparableNumber)
			counter ++;

	cout << counter << endl;

	return 0;
}
