#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;


int main () {
	set<string> stringsSet;
	
	while (true) {
		char operation;
		cin >> operation;

		if (operation == '+') {
			string str;
			cin >> str;
			stringsSet.insert(str);
		}

		else if (operation == '-') {
			string str;
			cin >> str;
			stringsSet.erase(str);
		}

		else if (operation == '?') {
			string str;
			cin >> str;
			set<string>::iterator iter = stringsSet.find(str);

			if (iter == stringsSet.end())
				cout << "NO" << endl;

			else
				cout << "YES" << endl;
		}

		else {
			break;
		}
	}

	return 0;
}
