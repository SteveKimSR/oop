#ifndef PUYO_H
#define	PUYO_H

#include <iostream>

class Gmap;											// Declaration of classes
class pointer;
class block;

class puyo {

private:
	Gmap* gameMap;									
	pointer* position;								
	block* Block;

	char insertKey;									// key from user
	int score;										// score
	bool onGoing;									// boolean checking if it needs to create a block or not
public:
	puyo();											// constructor

	void set_seed(int);
	int random(int);								// method for getting random int
	void run();										// EXECUTING METHOD

	void createBlock();								// method for making a new block
	void get_key();									// method for getting key
	void key(char);									// method for key
	void pressX();
	void explodeAndScore();							// method if collision has occured, explode and score

};

#endif
