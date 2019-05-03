#include <iostream>
#include <fstream>
#include <set>

using namespace std;


template <class Type>
class MedianSet {
	private:
		set<Type> lowSet;
		set<Type> hiSet;

		void relocate () {
			size_t delta = (lowSet.size() + hiSet.size()) % 2;

			if (lowSet.size() == hiSet.size() + delta)
				return;

			while (lowSet.size() < hiSet.size() + delta) {
				Type tmp = *hiSet.begin();
				hiSet.erase(tmp);
				lowSet.insert(tmp);
			}

			while (lowSet.size() > hiSet.size() + delta) {
				Type tmp = *prev(lowSet.end());
				lowSet.erase(tmp);
				hiSet.insert(tmp);
			}
		}

	public:
		void add (Type el) {
			set<Type> *choosedSet = ((!hiSet.empty() && el > *(hiSet.begin())) ? &hiSet : &lowSet);
			choosedSet->insert(el);
			relocate();
		}

		Type min () {
			Type ans = *lowSet.begin();
			lowSet.erase(ans);
			relocate();
			return ans;
		}

		Type max () {
			set<Type> *choosedSet = (hiSet.size() == 0 ? &lowSet : &hiSet);
			Type ans = *prev(choosedSet->end());
			choosedSet->erase(ans);
			relocate();
			return ans;
		}

		Type mid () {
			Type ans = *prev(lowSet.end());
			lowSet.erase(ans);
			relocate();
			return ans;
		}
};


int main () {
	MedianSet<size_t> medianSet;

	size_t querriesCount;
	cin >> querriesCount;

	for (size_t i = 0; i < querriesCount; i ++) {
		string command;
		cin >> command;

		if (command == "add") {
			size_t num;
			cin >> num;
			medianSet.add(num);
		}

		else if (command == "min") {
			cout << medianSet.min() << endl;
		}

		else if (command == "max") {
			cout << medianSet.max() << endl;
		}

		else if (command == "mid") {
			cout << medianSet.mid() << endl;
		}
	}

	return 0;
}
