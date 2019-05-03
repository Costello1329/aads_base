#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	map<string, size_t> wordRate;

	while (true) {
		string str;
		
		if (!(cin >> str))
			break;

		wordRate[str] ++;
	}


	vector<pair<size_t, string> > wordList;

	for (map<string, size_t>::iterator iter = wordRate.begin(); iter != wordRate.end(); iter ++) {
		wordList.push_back(make_pair(iter->second, iter->first));
	}

	sort(wordList.begin(), wordList.end(), [](const pair<size_t, string> &firstElement, const pair<size_t, string> &secondElement){
		if (firstElement.first != secondElement.first)
			return firstElement.first > secondElement.first;

		else
			return lexicographical_compare(firstElement.second.begin(), firstElement.second.end(), secondElement.second.begin(), secondElement.second.end());
	});

	for (const pair<size_t, string> &element: wordList)
		cout << element.second << endl;

	return 0;
}
