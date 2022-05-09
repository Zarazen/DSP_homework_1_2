#include <iostream>
#include "help.h"
#include "conga.h"

int main() {

	char command[16];
	commandEnum type;
	bool work = true;
	Conga congaLines;

	while (work) {

		std::cout << "Enter command\n";
		std::cin >> command;
		type = getType(command);

		switch (type) {

		case append: {

			char name[32], uni[8];
			int index;

			std::cout << "Enter name\n";
			std::cin >> name;
			name[std::strlen(name)] = '\0';
			std::cout << "Enter uni\n";
			std::cin >> uni;
			uni[std::strlen(uni)] = '\0';
			std::cout << "Enter line index\n";
			std::cin >> index;
			congaLines.append(name, uni, index);
			break;

		}

		case removeLast: {

			int index;

			std::cout << "Enter index\n";
			std::cin >> index;
			congaLines.removeLast(index);
			break;

		}
		case removeFirst: {

			int index;

			std::cout << "Enter index\n";
			std::cin >> index;
			congaLines.removeFirst(index);
			break;

		}
		case Remove: {

			int index;
			char name[32];

			std::cout << "Enter name\n";
			std::cin >> name;
			name[std::strlen(name)] = '\0';
			std::cout << "Enter index\n";
			std::cin >> index;
			congaLines.Remove(name, index);
			break;

		}
		case merge: {

			int index1, index2;

			std::cout << "Enter index 1\n";
			std::cin >> index1;
			std::cout << "Enter index 2\n";
			std::cin >> index2;
			congaLines.merge(index1, index2);
			break;

		}
		case print: {

			congaLines.print();
			break;

		}
		case quit: work = false; break;
		case invalid:std::cout << "Invalid command\n"; break;

		}
		
	}

	return 0;

}