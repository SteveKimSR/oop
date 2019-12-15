#ifndef CROSS_H
#define CROSS_H
#include "block.h"
class cross: public block{
private:
	int color[5];
	int shape;
public:
	cross();
	void set_color(int, int);
	int get_color(int);
	int type();
	int get_shape();
	void set_shape(int);
	void rotateLeft(pointer*);
	void rotateRight(pointer*);
};

#endif
