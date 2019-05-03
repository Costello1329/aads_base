#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	size_t count;
	cin >> count;

	priority_queue<double, vector<double>, greater<double> > calculationQueue;

	for (size_t i = 0; i < count; i ++) {
		double num;
		cin >> num;
		calculationQueue.emplace(num);
	}

	double value = 0;

	while (calculationQueue.size() != 1) {
		const double first = calculationQueue.top();
		calculationQueue.pop();
		const double second = calculationQueue.top();
		calculationQueue.pop();

		const double sum = first + second;
		calculationQueue.emplace(sum);

		value += sum;
	}

	cout << setprecision(2) << fixed << (double)value/20 << endl;

	return 0;
}
