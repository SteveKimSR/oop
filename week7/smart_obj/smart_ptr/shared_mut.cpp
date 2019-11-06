//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
shared_mut::shared_mut() {
    _mgr = new mgr();
}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}

shared_mut::shared_mut(const shared_mut &shared){
	_mgr = shared._mgr;
	increase();
}

void shared_mut::increase(){
	this->_mgr->count++;
}

Object* shared_mut::get() const{
	return this->_mgr->ptr;
}

void shared_mut::release(){
	this->_mgr->count--;
	if(this->_mgr->count == 0){
		delete(_mgr);
	}else{
		this->_mgr = new mgr();
	}
}

int shared_mut::count(){
	return this->_mgr->count;
}

shared_mut shared_mut::operator+(const shared_mut &shared){
	int sum = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	return shared_mut(new Object(sum));
}

shared_mut shared_mut::operator-(const shared_mut &shared){
	int sub = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	return shared_mut(new Object(sub));
}

shared_mut shared_mut::operator*(const shared_mut &shared){
	int mul = this->_mgr->ptr->get() * shared._mgr->ptr->get();
	return shared_mut(new Object(mul));
}

shared_mut shared_mut::operator/(const shared_mut &shared){
	int div = this->_mgr->ptr->get() / shared._mgr->ptr->get();
	return shared_mut(new Object(div));
}

Object* shared_mut::operator->(){
	return this->_mgr->ptr;
}

shared_mut& shared_mut::operator=(const shared_mut &r){
	release();
	this->_mgr = r._mgr;
	increase();
}
} // end of namespace ptr
