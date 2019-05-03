#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	map<string, map<string, size_t> > journal;

	while (true) {
		string name, thing;
		size_t count;
		
		if (!(cin >> name >> thing >> count))
			break;

		journal[name][thing] += count;
	}

	for (auto firstIter = journal.begin(); firstIter != journal.end(); firstIter ++) {
		cout << firstIter->first << ":" << endl;

		const map<string, size_t> counts = firstIter->second;

		for (auto secondIter = counts.begin(); secondIter != counts.end(); secondIter ++) {
			cout << secondIter->first << " " << secondIter->second << endl;
		}
	}

	return 0;
}
