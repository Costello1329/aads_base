#include <iostream>
#include <list>

using namespace std;


int main () {
	list<char> line;
	auto iter = line.begin();
	char ch;

	while (cin.get(ch)) {
		if (ch == '<') {
			if (iter != line.begin())
				-- iter;
		}

		else if (ch == '>') {
			if (iter != line.end())
				++ iter;
		}

		else if (ch == '#') {
			if (iter == line.end())
				continue;

			iter = line.erase(iter);
		}

		else if (ch == '@') {
			if (iter == line.begin())
				continue;

			-- iter;
			iter = line.erase(iter);
		}

		else if (ch == '^')
			iter = line.begin();

		else if (ch == '$')
			iter = line.end();

		else if (ch == '\n')
			break;

		else
			line.insert(iter, ch);
	}

	for (const char &ch: line)
		cout << ch;

	cout << endl;

	return 0;
}
