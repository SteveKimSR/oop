#ifndef FOLD_H
#define FOLD_H

#include "block.h"

class fold : public block{
private:
	int color[3];
	int shape;
public:
	fold();
	void set_color(int, int);
	int get_color(int);
	int type();
	int get_shape();
	void set_shape(int);
	void rotateLeft(pointer*);
	void rotateRight(pointer*);
};

#endif
