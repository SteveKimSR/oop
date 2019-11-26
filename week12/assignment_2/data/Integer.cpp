#include "Integer.h"

Integer::Integer(int value){
	this->_val = value;
}

int Integer::val(){
	return this->_val;
}

void Integer::set_val(const int& value){
	this->_val = value;
}

json_object* Integer::parse(const char* str, int length){

	std::string st;
	while(*str >= 48 && *str <=57){
		_index++;
		st+=*str;
		str++;
	}
//	for(int i = 0; i < length; i++){
//		_index++;
//		st += *str;
//		str++;
//	}
	_index--;
	return new Integer(stoi(st));

}
json_object::_type Integer::type(){
	return INT;
}
std::string Integer::to_string(){
	return std::to_string(_val);
}
