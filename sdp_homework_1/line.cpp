#include <iostream>
#include "help.h"
#include "line.h"

Line::Line() {

	beg = nullptr;

	end = nullptr;

}

Line::~Line() {

	destroy();

}

Line& Line::operator=(Line& dummy) {

	if (this != &dummy) {

		Person* copy;
		Person* newBeg = nullptr;
		Person* curr = nullptr;
		copy = dummy.beg;

		if (copy != nullptr) {

			try {

				newBeg = new Person;
				newBeg->prev = nullptr;
				newBeg->name = nullptr;
				newBeg->uni = nullptr;
				curr = newBeg;
				newBeg->name = new char[safeLen(copy->name)];
				safeCpy(newBeg->name, copy->name);
				newBeg->uni = new char[safeLen(copy->uni)];
				safeCpy(newBeg->uni, copy->uni);
				copy = copy->next;

			}
			catch (std::bad_alloc) {

				std::cout << "Insufficient memory\n";

				if (newBeg == nullptr)
					return *this;

				if (newBeg->name != nullptr)
					delete[] newBeg->name;

				if (newBeg->uni != nullptr)
					delete[] newBeg->uni;

				delete newBeg;

				return *this;

			}

		}

		while (copy != nullptr) {

			try {

				curr->next = new Person;
				curr->next->prev = curr;
				curr = curr->next;
				curr->name = nullptr;
				curr->uni = nullptr;
				curr->name = new char[safeLen(copy->name)];
				safeCpy(curr->name, copy->name);
				curr->uni = new char[safeLen(copy->uni)];
				safeCpy(curr->uni, copy->uni);
				copy = copy->next;

			}
			catch (std::bad_alloc) {

				std::cout << "Insufficient memory\n";

				destroyElements(newBeg, curr);

				if (curr == nullptr)
					return *this;

				if (curr->name != nullptr)
					delete[] curr->name;

				if (curr->uni != nullptr)
					delete[] curr->uni;

				delete curr;

				return *this;

			}

		}

		destroy();

		beg = newBeg;
		end = curr;
		end->next = nullptr;

	}

	return *this;

}

void Line::append(const char* name, const char* uni) {

	if (!isFriendlyWithLast(uni)) {

		std::cout << "Person is not friendly\n";
		return;

	}

	if (end == nullptr) {

		try {

			beg = new Person;
			beg->prev = nullptr;
			beg->next = nullptr;
			beg->name = nullptr;
			beg->uni = nullptr;
			end = beg;

			end->name = new char[safeLen(name)];
			safeCpy(end->name, name);
			end->uni = new char[safeLen(uni)];
			safeCpy(end->uni, uni);

		}
		catch (std::bad_alloc) {

			std::cout << "Insufficient memory\n";

			if (beg == nullptr)
				return;

			if (beg->name != nullptr)
				delete[] beg->name;

			if (beg->uni != nullptr)
				delete[] beg->uni;

			delete beg;
			beg == nullptr;
			end = nullptr;

		}

	}
	else {

		Person* curr = nullptr;

		try {

			curr = new Person;
			curr->prev = end;
			curr->name = nullptr;
			curr->uni = nullptr;
			curr->next = nullptr;

			curr->name = new char[safeLen(name)];
			safeCpy(curr->name, name);
			curr->uni = new char[safeLen(uni)];
			safeCpy(curr->uni, uni);

		}
		catch (std::bad_alloc) {

			std::cout << "Insufficient memory\n";

			if (curr == nullptr)
				return;

			if (curr->name != nullptr)
				delete[] curr->name;

			if (curr->uni != nullptr)
				delete[] curr->uni;

			delete curr;

			return;

		}

		end->next = curr;
		end = curr;

	}

}

void Line::removeLast() {

	if (beg == end) {

		delete[] beg->name;
		delete[] beg->uni;
		delete[] beg;
		beg = nullptr;
		end = nullptr;

	}
	else {

		delete[] end->name;
		delete[] end->uni;
		end = end->prev;
		delete end->next;
		end->next = nullptr;

	}

}

void Line::removeFirst() {

	if (beg == end) {

		delete[] beg->name;
		delete[] beg->uni;
		delete[] beg;
		beg = nullptr;
		end = nullptr;

	}
	else {

		delete[] beg->name;
		delete[] beg->uni;
		beg = beg->next;
		delete beg->prev;
		beg->prev = nullptr;

	}

}

void Line::Remove(const char* name) {

	if (beg == end) {

		if (safeCmp(beg->name, name)) {

			delete[] beg->name;
			delete[] beg->uni;
			delete beg;
			beg = nullptr;
			end = nullptr;
			return;

		}

	}
	else {

		Person* curr = beg;

		while (curr != nullptr) {

			if (safeCmp(curr->name, name)) {

				if (curr == beg) {

					delete[] beg->name;
					delete[] beg->uni;
					beg = beg->next;
					delete beg->prev;
					beg->prev = nullptr;
					return;

				}

				if (curr == end) {

					delete[] end->name;
					delete[] end->uni;
					end = end->prev;
					delete end->next;
					end->next = nullptr;
					return;

				}

				delete[] curr->name;
				delete[] curr->uni;
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				delete curr;
				return;

			}

			curr = curr->next;

		}

	}

	std::cout << "Person not found\n";

}

Line& Line::operator+=(Line& dummy) {

	if (this != &dummy) {

		if (isFriendlyWithLast(dummy.beg->uni)) {

			end->next = dummy.beg;
			dummy.beg->prev = end;
			end = dummy.end;
			dummy.beg = nullptr;
			dummy.end = nullptr;

		}
		else
			std::cout << "Incompatible people\n";

	}

	return *this;

}

void Line::print() {

	Person* copy = beg;

	while (copy != nullptr) {

		if (copy->next != nullptr)
			std::cout << "(" << copy->name << ", " << copy->uni << ") - ";
		else
			std::cout << "(" << copy->name << ", " << copy->uni << ")";

		copy = copy->next;

	}

	std::cout << std::endl;

}

bool Line::isEmpty() {

	if (beg == nullptr)
		return true;

	return false;

}

void Line::destroy() {

	Person* curr = beg;
	Person* theNext = nullptr;
	if (curr != nullptr)
		theNext = curr->next;

	while (curr != nullptr) {

		delete[] curr->name;
		delete[] curr->uni;
		delete curr;
		curr = theNext;
		if (theNext != nullptr)
			theNext = theNext->next;

	}

	beg = nullptr;
	end = nullptr;

}

void Line::destroyElements(Person* from, Person* to) {

	Person* curr;
	Person* prev;
	curr = from;

	while (curr != to) {

		delete[] curr->name;
		delete[] curr->uni;
		prev = curr;
		curr = curr->next;
		delete prev;

	}

}

bool Line::isFriendlyWithLast(const char* uni) {

	if (end == nullptr)
		return true;

	if (safeCmp(uni, "fmi") && safeCmp(end->uni, "unss"))
		return false;

	if (safeCmp(uni, "tu") && safeCmp(end->uni, "fmi"))
		return false;

	if (safeCmp(uni, "unss") && safeCmp(end->uni, "tu"))
		return false;

	return true;

}
