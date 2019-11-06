//
// Created by 김혁진 on 14/10/2019.
//

#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}

Object* unique_immut::get() const{
	return this->_mgr->ptr; 
}


void unique_immut::release(){
	if(this->_mgr != nullptr)
		this->_mgr->ptr = nullptr;
}

unique_immut unique_immut::operator+(unique_immut &unique){
	int sum = this->_mgr->ptr->get() + unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(sum));
}
unique_immut unique_immut::operator-(unique_immut &unique){
	int sub = this->_mgr->ptr->get() - unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(sub));
}

unique_immut unique_immut::operator*(unique_immut &unique){
	int mul = this->_mgr->ptr->get() * unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(mul));
}
unique_immut unique_immut::operator/(unique_immut &unique){
	int div = this->_mgr->ptr->get() / unique._mgr->ptr->get();
	this->release();
	unique.release();
	return unique_immut(new Object(div));
}

Object* unique_immut::operator->(){
	return this->_mgr->ptr;
}
unique_immut& unique_immut::operator=(unique_immut &r){
	release();
	if(this->_mgr != r._mgr){
		this->_mgr = r._mgr;
	}
	return *this;
}
} // end of namespace ptr
