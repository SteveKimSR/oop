#include "String.h"

String::String(const std::string& str){

	this->_val = str;

}

std::string String::val(){

	return this->_val;

}

void String::set_val(const std::string& str){

	this->_val = str;

}

json_object* String::parse(const char* str, int length, char base){	

	std::string st;
	if(*str == '\'' || *str == '"'){
		str++;
	}
	while(true){

		_index++;

		if(*str == base){

			break;
		}

		st += *str;

		str++;

	}
	
	return new String(st);

}
json_object::_type String::type(){

	return STRING;

}
std::string String::to_string(){
	
	return "'"+_val+"'";
}
