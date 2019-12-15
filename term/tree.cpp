#include "tree.h"
#include "pointer.h"

tree::tree(){
	this->shape = 1;
}

void tree::set_color(int index, int newColor){
		this->color[index] = newColor;
}

int tree::get_color(int index){
	return this->color[index];
}

int tree::type(){
	return 2;
}

int tree::get_shape(){
	return this->shape;
}
void tree::set_shape(int s){
	this->shape = s;
}
void tree::rotateLeft(pointer* p){
	if(this->get_shape() == 1){
		this->set_shape(4);
	}else{
		this->set_shape(this->get_shape()-1);
	}
	if((this->get_shape() == 2) || (this->get_shape() == 4)){
		if(p->get_x() == 0){
			p->set_x(1);
		}else if(p->get_x() == 4){
			p->set_x(3);
		}
	}
}
void tree::rotateRight(pointer* p){
	if(this->get_shape() == 4){
		this->set_shape(1);
	}else{
		this->set_shape(this->get_shape()+1);
	}
	if((this->get_shape() == 2) || (this->get_shape() == 4)){
		if(p->get_x() == 0){
			p->set_x(1);
		}else if(p->get_x() == 4){
			p->set_x(3);
		}
	}
}
