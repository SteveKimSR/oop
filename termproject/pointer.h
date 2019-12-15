#ifndef POINTER_H
#define POINTER_H

#include "puyo.h"
#include "block.h"
class pointer{
private:
	int x;
	int y;
public:
	pointer();
	pointer(int, int);
	int get_x();
	int get_y();
	void left(block*);
	void right(block*);
	void down();
	void set_x(int);
	void set_y(int);
	void reset();
};

#endif
