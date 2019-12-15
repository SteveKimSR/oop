#ifndef MAP_H
#define MAP_H

#include "puyo.h"

class Gmap{

private:
	int field[12][5];

public:
	Gmap();
	void init();
	void print();
	bool checkAvaliable(block*, pointer*);
	void insertBlock(block*, pointer*);
	void removeBlock(block*, pointer*);
	void dropBlock(block*, pointer*);
	int checkEnd(int);
	bool checkCollision(block*, pointer*);							// method checking if collision with block and Gmap
	bool explode();
	void visitAll(int, int, pointer [], bool [12][5]);
	void visitOne(int, int);
	void makeClean();
};

#endif
