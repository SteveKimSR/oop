#include "fold.h"
#include "puyo.h"

fold::fold(){
	this->shape = 1;
}

void fold::set_color(int index, int newColor){
	this->color[index] = newColor;
}
int fold::get_color(int index){
	return this->color[index];
}

int fold::type(){
	return 1;
}

int fold::get_shape(){
	return this->shape;
}
void fold::set_shape(int s){
	this->shape = s;
}
void fold::rotateLeft(pointer* p){
	if(this->get_shape() == 1){
		this->set_shape(4);
	}else{
		this->set_shape(this->get_shape()-1);
	}
}
void fold::rotateRight(pointer* p){
	if(this->get_shape() == 4){
		this->set_shape(1);
	}else{
		this->set_shape(this->get_shape()+1);
	}
}
