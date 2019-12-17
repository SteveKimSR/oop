#include <ctime>
#include <cstdlib>
#include "puyo.h"

#include "Gmap.h"
#include "pointer.h"
#include "block.h"

#include "fold.h"
#include "tree.h"
#include "cross.h"

puyo::puyo(){											// puyo 생성자.
	this->gameMap = new Gmap();
	this->gameMap->init();
	this->position = new pointer();
	this->Block = nullptr;
	this->insertKey = '0';
	this->score = 0;
}
void puyo::set_seed(int s){
	srand((unsigned int)s);
}
int puyo::random(int max){								// 랜덤값 사용을 위한 random 함수
	return (rand()%max + 1);
}

void puyo::run(){										// puyo 실행
	this->createBlock();
	while(this->gameMap->checkAvaliable(this->Block, this->position)){
		system("clear");
		std::cout << "score : " << score << std::endl;
		std::cout << "" << std::endl;
		this->gameMap->insertBlock(this->Block, this->position);
		this->gameMap->print();
		this->gameMap->removeBlock(this->Block, this->position);
		std::cout << "move: ";

		this->get_key();
		this->key(insertKey);

		if(this->gameMap->checkCollision(this->Block, this->position)){
			this->gameMap->dropBlock(this->Block, this->position);

			this->explodeAndScore();

			this->position->reset();
			this->createBlock();
		}
	}
	std::cout << "NEW block : ";
	int t = this->Block->type();
	if(t == 1){
		std::cout << "FOLD" << std::endl;
	}else if(t == 2){
		std::cout << "TREE" << std::endl;
	}else{
		std::cout << "CROSS" << std::endl;
	}
	std::cout << "Game Over!" << std::endl;
}

void puyo::createBlock(){
	srand((unsigned int)time(0));
	int r = random(3);
	int j;
	if(this->Block != nullptr){
		delete(this->Block);
	}
	if((r == 1) || (r == 2)){
		if(r == 1){
			this->Block = new fold();
		}else{
			this->Block = new tree();
		}
		for(int i = 0; i < 3; i++){
			j = this->random(4);
			this->Block->set_color(i, j);
			set_seed(j);
		}
	}else if(r == 3){
		this->Block = new cross();
		for(int i=0;i<5;i++){
			j = this->random(4);
			this->Block->set_color(i, j);
			set_seed(j);
		}
	}
}


void puyo::get_key(){								// key를 입력받음. 틀리면 다시 입력받음.
	while(true){
		std::cin >> this->insertKey;
		if((insertKey == 'q') ||(insertKey == 'e') ||(insertKey == 'a') ||(insertKey == 's') ||(insertKey == 'd') ||(insertKey == 'x')){
			break;
		}if(insertKey == 'p')
			exit(0);
		std::cout << "please move again: " ;
	}
	
}

void puyo::key(char insertKey){							// 키 입력 처리.
	if(insertKey == 'a'){
		this->position->left(this->Block);
		if(this->gameMap->checkAvaliable(this->Block, this->position)){
		}else{
			this->position->right(this->Block);
		}
	}else if(insertKey == 'd'){
		this->position->right(this->Block);
		if(this->gameMap->checkAvaliable(this->Block, this->position)){
		}else{
			this->position->left(this->Block);
		}
	}else if(insertKey == 's'){
		this->position->down();	
	}else if(insertKey == 'q'){
		if(this->gameMap->checkAvaliable(this->Block, this->position)){
			this->Block->rotateLeft(this->position);
		}
	}else if(insertKey == 'e'){
		if(this->gameMap->checkAvaliable(this->Block, this->position)){
			this->Block->rotateRight(this->position);
		}
	}else if(insertKey == 'x'){
		this->pressX();
	}
}

void puyo::pressX(){
	int s = this->Block->get_shape();
	int t = this->Block->type();
	int x = this->position->get_x();
	int temp[3], here = 0;
	if(t == 1){
		if(s == 3){
			if(this->gameMap->checkEnd(x) < (this->gameMap->checkEnd(x+1)+1)){
				this->position->set_y(this->gameMap->checkEnd(x));
			}else{
				this->position->set_y(this->gameMap->checkEnd(x+1)+1);
			}
		}else if(s == 4){
			if((this->gameMap->checkEnd(x)+1) < this->gameMap->checkEnd(x+1)){
				this->position->set_y(this->gameMap->checkEnd(x)+1);
			}else{
				this->position->set_y(this->gameMap->checkEnd(x+1));
			}
		}else {
			if(this->gameMap->checkEnd(x) < this->gameMap->checkEnd(x+1)){
				this->position->set_y(this->gameMap->checkEnd(x));
			}else{
				this->position->set_y(this->gameMap->checkEnd(x));
			}
		}
	}else if(t == 2){
		if((s == 1) || (s == 3)){
			this->position->set_y(this->gameMap->checkEnd(x)-1);
		}else{
			temp[0] = this->gameMap->checkEnd(x-1);
			temp[1] = this->gameMap->checkEnd(x);
			temp[2] = this->gameMap->checkEnd(x+1);
			for(int i = 1; i < 3; i++){
				if(temp[here] > temp[i]){
					here = i;
				}
			}
			this->position->set_y(temp[here]);
		}
	}else if(t == 3){
		temp[1] = this->gameMap->checkEnd(x-1);
		temp[0] = this->gameMap->checkEnd(x);
		temp[2] = this->gameMap->checkEnd(x+1);
		for(int i = 1; i < 3; i++){
			if(temp[here] > (temp[i]+1)){
				here = i;
			}
		}
		if(here == 0){
			this->position->set_y(temp[here]-1);
		}else{
			this->position->set_y(temp[here]);
		}
	}
}

void puyo::explodeAndScore(){
	while(this->gameMap->explode()){
		this->gameMap->makeClean();
		score++;
	}
}
