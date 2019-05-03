#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	map<string, long long> bank;

	size_t operationsCount;
	cin >> operationsCount;

	for (size_t i = 0; i < operationsCount; i ++) {
		size_t operation;
		string name;
		cin >> operation >> name;

		if (operation == 1) {
			long long delta;
			cin >> delta;
			bank[name] += delta;
		}

		else {
			if (bank.count(name) == 0)
				cout << "ERROR" << endl;

			else
				cout << bank[name] << endl;
		}
	}

	return 0;
}
