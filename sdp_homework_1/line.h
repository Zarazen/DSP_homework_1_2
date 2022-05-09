#ifndef _line_h_
#define _line_h_

int safeLen(const char* input);

void safeCpy(char* to, const char* from);

bool safeCmp(const char* str1, const char* str2);

class Line{

public:

	Line();
	~Line();
	Line& operator=(Line& dummy);

	void append(const char* name, const char* uni);
	void removeLast();
	void removeFirst();
	void Remove(const char* name);
	Line& operator+=(Line& dummy);
	void print();
	bool isEmpty();
	void destroy();

private:

	Line(const Line& dummy) = delete;

	struct Person {

		Person* prev;
		Person* next;
		char* name;
		char* uni;

	};

	void destroyElements(Person* from, Person* to);
	bool isFriendlyWithLast(const char* uni);

	Person* beg;
	Person* end;

};

#endif // !_line_h_

