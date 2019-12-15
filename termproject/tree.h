#ifndef TREE_H
#define TREE_H

#include "block.h"

class tree : public block{
private:
	int color[3];
	int shape;
public:
	tree();
	void set_color(int, int);
	int get_color(int);
	int type();
	int get_shape();
	void set_shape(int);
	void rotateLeft(pointer*);
	void rotateRight(pointer*);
};
#endif
