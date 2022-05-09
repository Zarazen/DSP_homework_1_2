#include <iostream>
#include "conga.h"
#include "line.h"

Conga::Conga() {

	lines = new Line[start];
	cap = start;
	numLines = start;

}

Conga::~Conga() {

	delete[] lines;

}

void Conga::append(const char* name, const char* uni, const int& index) {


	if (index < 1) {

		std::cout << "Invalid index\n";
		return;

	}

	if (index > numLines) {

		if (lines[numLines - 1].isEmpty()) {

			lines[numLines - 1].append(name, uni);
			return;

		}

		checkFreeSpace();
		lines[numLines].append(name, uni);
		++numLines;
		return;

	}

	lines[index - 1].append(name, uni);

}

void Conga::removeLast(const int& index) {

	if (index < 1 || index > numLines) {

		std::cout << "Invalid index\n";
		return;

	}

	lines[index - 1].removeLast();

	if (lines[index - 1].isEmpty()) {

		clearEmpty(index);
		checkForResize();

	}

}

void Conga::removeFirst(const int& index) {

	if (index<1 || index>numLines) {

		std::cout << "Invalid index\n";
		return;

	}

	lines[index - 1].removeFirst();

	if (lines[index - 1].isEmpty()) {

		clearEmpty(index);
		checkForResize();

	}

}

void Conga::Remove(const char* name, const int& index) {

	if (index<1 || index>numLines) {

		std::cout << "Invalid index\n";
		return;

	}

	lines[index - 1].Remove(name);

	if (lines[index - 1].isEmpty()) {

		clearEmpty(index);
		checkForResize();

	}

}

void Conga::merge(const int& index1, const int& index2) {

	if (index1 < 1 || index2 < 1 || index1 > numLines || index2 > numLines) {

		std::cout << "Invalid index\n";
		return;

	}

	lines[index1 - 1] += lines[index2 - 1];

	clearEmpty(index2);
	checkForResize();

}

void Conga::print() {

	for (int i = 0; i < numLines; ++i)
		lines[i].print();

}

void Conga::checkFreeSpace() {

	if (numLines == cap)
		resize(increase);

}

void Conga::resize(const bool increaseOrDecrease) {

	if (increaseOrDecrease) {

		Line* newLines = new Line[cap * increaseSize];
		for (int i = 0; i < cap; ++i)
			newLines[i] = lines[i];

		cap *= increaseSize;
		delete[] lines;
		lines = newLines;

	}
	else {

		Line* newLines = new Line[int(decreaseSize * cap)];
		for (int i = 0; i < numLines; ++i)
			newLines[i] = lines[i];

		cap = int(decreaseSize * cap);
		delete[] lines;
		lines = newLines;

	}

}

void Conga::checkForResize() {

	if (numLines < int(decreaseSize * cap))
		resize(decrease);

}

void Conga::clearEmpty(const int& index) {

	if (index == numLines) {

		lines[numLines - 1].destroy();
		--numLines;
		return;

	}

	for (int i = index - 1; i < numLines - 1; ++i)
		lines[i] = lines[i + 1];

	lines[numLines - 1].destroy();
	--numLines;

}

