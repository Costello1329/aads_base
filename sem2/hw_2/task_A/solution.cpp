#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Command {
	size_t commandId;
	size_t solvedProblemsCount;
	size_t penalty;
};

int main () {
	size_t commandsCount;
	cin >> commandsCount;

	vector<Command> commands(commandsCount);
	commands.reserve(commandsCount);

	for (size_t i = 0; i < commandsCount; i ++) {
		commands[i].commandId = i + 1;
		cin >> commands[i].solvedProblemsCount >> commands[i].penalty;
	}

	sort(commands.begin(), commands.end(), [](const Command &firstCommand, const Command &secondCommand){
		if (firstCommand.solvedProblemsCount != secondCommand.solvedProblemsCount)
			return firstCommand.solvedProblemsCount > secondCommand.solvedProblemsCount;

		else {
			if (firstCommand.penalty != secondCommand.penalty)
				return firstCommand.penalty < secondCommand.penalty;

			else
				return firstCommand.commandId < secondCommand.commandId;
		}
	});

	for (const Command &command: commands)
		cout << command.commandId << " ";

	cout << endl;

	return 0;
}
