#include <iostream>
#include "help.h"

const char* commands[] = { "append","removeLast","removeFirst","remove","merge","print","quit" };

commandEnum getType(const char* input) {

	for (int i = 0; i < numComm; ++i) {

		if (!std::strcmp(commands[i], input))
			return commandEnum(i);

	}

	return invalid;

}

int safeLen(const char* input) {

	for (int i = 0;; ++i) {

		if (input[i] == '\0')
			return i + 1;

	}

}

void safeCpy(char* to, const char* from) {

	for (int i = 0;; ++i) {

		to[i] = from[i];


		if (from[i] == '\0')
			break;

	}

}

bool safeCmp(const char* str1, const char* str2) {

	for (int i = 0;; ++i) {

		if (str1[i] != str2[i])
			return false;

		if (str1[i] == '\0')
			break;

	}

	return true;

}
