#include "pointer.h"

pointer::pointer(){
	this->x = 2;
	this->y = 1;
}

pointer::pointer(int x, int y){
	this->x = x;
	this->y = y;
}
int pointer::get_x(){
	return this->x;
}
int pointer::get_y(){
	return this->y;
}
void pointer::left(block* b){
	int type = b->type();
	if(type == 1){
		if(this->get_x() != 0){
			this->set_x(this->get_x()-1);
		}
	}else if(type == 2){
		if(this->get_x() != 0){
			this->set_x(this->get_x()-1);
		}
	}else if(type == 3){
		if(this->get_x() != 1){
			this->set_x(this->get_x()-1);
		}
	}
}
void pointer::right(block* b){
	int type = b->type();
	if(type == 1){
		if(this->get_x() != 3){
			this->set_x(this->get_x()+1);
		}
	}else if(type == 2){
		if(this->get_x() != 4){
			this->set_x(this->get_x()+1);
		}
	}else if(type == 3){
		if(this->get_x() != 3){
			this->set_x(this->get_x()+1);
		}
	}
}
void pointer::down(){
	this->set_y(this->get_y()+1);
}
void pointer::set_x(int x){
	this->x = x;
}
void pointer::set_y(int y){
	this->y = y;
}
void pointer::reset(){
	this->set_x(2);
	this->set_y(1);
}
