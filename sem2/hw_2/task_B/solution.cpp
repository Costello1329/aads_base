#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


int main () {
	size_t arraySize;
	cin >> arraySize;

	vector<size_t> array(arraySize);
	array.reserve(arraySize);

	for (size_t &num: array)
		cin >> num;

	size_t querriesCount;
	cin >> querriesCount;

	for (size_t i = 0; i < querriesCount; i ++) {
		size_t querry;
		cin >> querry;

		const vector<size_t>::iterator up = upper_bound(array.begin(), array.end(), querry);
		const vector<size_t>::iterator low = lower_bound(array.begin(), array.end(), querry);

		cout << distance(low, up) << endl;
	}

	return 0;
}
