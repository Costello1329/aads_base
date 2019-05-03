#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;


int main () {
	map<string, string> dict;

	size_t sinonimusCount;
	cin >> sinonimusCount;

	for (size_t i = 0; i < sinonimusCount; i ++) {
		string word1, word2;
		cin >> word1 >> word2;
		dict[word1] = word2;
		dict[word2] = word1;
	}

	string word;
	cin >> word;

	for (map<string, string>::iterator iter = dict.begin(); iter != dict.end(); iter ++) {
		if (iter->first == word)
			cout << iter->second << endl;
	}

	return 0;
}
