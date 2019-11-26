#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list(){
	
}

json_object* json_list::parse(const char* str, int length){

	json_list* returnlist = new json_list();

	for(_index += 1; _index < length; _index++){

		const char* thisone = str+_index;

		char index = str[_index];

//		std::cout << _index << ": "<< index << std::endl; // 디버깅용

		if(index == ' ' || index == ','){}

		else if(index == ']'){

			return returnlist;

		}

		else if(index == '{'){

			returnlist->v.push_back(json_dict::parse(str,length));

		}
		else if(index == '['){

			returnlist->v.push_back(json_list::parse(str, length));

		}
		else if(index == '\'' || index == '"'){

			returnlist->v.push_back(String::parse(thisone, length, index));

		}
		else if(index >= 48 && index <= 57){

			int count = _index;

			while(str[count] >= 48 && str[count] <= 57){

				count++;
				
			}

			returnlist->v.push_back(Integer::parse(thisone, count));
		}
	}

	str++;

	return returnlist;

}

json_object* json_list::operator[](int key) const{
	return v[key];
}
json_object::_type json_list::type(){
	return LIST;
}

std::string json_list::to_string(){	
	std::string input;
	input.append("[");
	for(std::vector<json_object*>::iterator it = v.begin() ;it != v.end(); it++){
		
		input.append((*it)->to_string());
		if((it+1) != v.end()){
			input.append(",");
		}
	}
	input.append("]");
	return input;
}
