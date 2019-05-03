#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	map<string, set<string> > dict;

	while (true) {
		string englishWord;

		if (!(cin >> englishWord))
			break;

		char delimeter;
		cin >> delimeter;

		string latinWord;

		while (true) {
			cin >> latinWord;
			
			if (latinWord[latinWord.size() - 1] == ',') {
				latinWord = latinWord.substr(0, latinWord.size() - 1);
				dict[latinWord].insert(englishWord);
			}

			else {
				dict[latinWord].insert(englishWord);
				break;
			}
		}
	}

	cout << dict.size() << endl;

	for (map<string, set<string> >::iterator mapIter = dict.begin(); mapIter != dict.end(); mapIter ++) {
		cout << mapIter->first << " - ";

		for (set<string>::iterator setIter = mapIter->second.begin(); setIter != mapIter->second.end(); setIter ++) {
			cout << *setIter;

			if (setIter != prev(mapIter->second.end()))
				cout << ", ";

			else
				cout << endl;
		}
	}

	return 0;
}
