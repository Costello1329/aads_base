#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Graph {
	private:
		vector<vector<size_t> > graph;

	public:
		Graph (const size_t &verticesCount) {
			graph.resize(verticesCount);
			graph.reserve(verticesCount);
		}

		void addEdge (const size_t &from, const size_t &to) {
			graph[from].push_back(to);
		}

		const vector<size_t>& getEdges (const size_t &from) {
			return graph[from];
		}
};


int main () {
	size_t verticesCount;
	cin >> verticesCount;

	Graph graph(verticesCount);

	size_t operationsCount;
	cin >> operationsCount;


	for (size_t i = 0; i < operationsCount; i ++) {
		size_t operationId;
		cin >> operationId;

		if (operationId == 1) {
			size_t from, to;
			cin >> from >> to;
			graph.addEdge(from - 1, to - 1);
			graph.addEdge(to - 1, from - 1);
		}

		else if (operationId == 2) {
			size_t from;
			cin >> from;

			for (const size_t &to: graph.getEdges(from - 1))
				cout << (to + 1) << " ";

			cout << endl;
		}

		else {
			throw "Bad operation id";
		}
	}


	return 0;
}
