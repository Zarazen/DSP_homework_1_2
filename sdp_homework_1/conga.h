#ifndef _conga_h_
#define _conga_h_

class Line;

class Conga{

public:

	Conga();
	~Conga();

	void append(const char* name, const char* uni, const int& index);
	void removeLast(const int& index);
	void removeFirst(const int& index);
	void Remove(const char* name, const int& index);
	void merge(const int& index1, const int& index2);
	void print();

private:

	Conga(const Conga& dummy) = delete;
	Conga& operator=(const Conga& dummy) = delete;

	void checkFreeSpace();
	void resize(const bool increaseOrDecrease);
	void checkForResize();
	void clearEmpty(const int& index);

	Line* lines;
	int numLines;
	int cap;

};

const bool increase = true;
const bool decrease = false;
const int start = 1;
const int increaseSize = 2;
const double decreaseSize = 0.75;

#endif // !_conga_h_