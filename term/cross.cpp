#include "cross.h"
#include "puyo.h"

cross::cross(){
	this->shape = 1;
}

void cross::set_color(int index, int newColor){
		this->color[index] = newColor;
}

int cross::get_color(int index){
	return this->color[index];
}

int cross::type(){
	return 3;
}

int cross::get_shape(){
	return this->shape;
}
void cross::set_shape(int s){
	this->shape = s;
}
void cross::rotateLeft(pointer* p){
	if(this->get_shape() == 1){
		this->set_shape(4);
	}else{
		this->set_shape(this->get_shape()-1);
	}
}
void cross::rotateRight(pointer* p){
	if(this->get_shape() == 4){
		this->set_shape(1);
	}else{
		this->set_shape(this->get_shape()+1);
	}
}
