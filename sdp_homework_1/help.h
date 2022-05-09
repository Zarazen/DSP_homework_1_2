#ifndef _help_h_
#define _help_h_

const char* commands[];

enum commandEnum {

	invalid = -1,
	append,
	removeLast,
	removeFirst,
	Remove,
	merge,
	print,
	quit,
	numComm

};

commandEnum getType(const char* input);

int safeLen(const char* input);

void safeCpy(char* to, const char* from);

bool safeCmp(const char* str1, const char* str2);

#endif // !_help_h_

