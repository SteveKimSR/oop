#ifndef BLOCK_H
#define BLOCK_H

#include "puyo.h"

class block{

public:
	virtual void set_color(int, int) = 0;
	virtual int get_color(int) = 0;
	virtual int type() = 0;
	virtual int get_shape() = 0;
	virtual void set_shape(int) = 0;
	virtual void rotateLeft(pointer*) = 0;
	virtual void rotateRight(pointer*) = 0;
};

#endif
