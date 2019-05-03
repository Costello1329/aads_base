#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	set<long long> numberSet;
	
	size_t operationsCount;
	cin >> operationsCount;

	long long carry = 0;

	for (size_t i = 0; i < operationsCount; i ++) {
		char operation;
		cin >> operation;

		long long num;
		cin >> num;

		if (operation == '+') {
			//cout << "added: " << num + carry << endl;
			const long long insertion = (num + carry) % 1000000000;
			numberSet.insert(insertion);
			carry = 0;
		}

		else {
			auto iter = numberSet.lower_bound(num);

			if (iter == numberSet.end()) {
				carry = -1;
			}

			else {
				carry = *iter;
			}

			cout << carry << endl;
			//cout << "out: " << carry << endl;
		}
	}

	return 0;
}
