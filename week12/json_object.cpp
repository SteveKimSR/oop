#include "json_object.h"

#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object* json_object::parse(const std::string& str) {

	
	int length = str.length();
	
	json_object::parse(str.c_str(), length);

}

json_object* json_object::parse(const char* str, int length){

		char temp = *str;

		if(temp == ' '){
			
		
		}else if(temp == '{'){
			
			json_dict::parse(str, length);

		}else if(temp == '['){

			json_list::parse(str, length);

		}else if(temp == '\'' || temp == '"'){

			String::parse(str, length, temp);

		}else{

			Integer::parse(str, length);

		}
	_index = 0;
}
