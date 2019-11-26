#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"


void json_dict::put(json_object* key, json_object* val){
	if(this->v.size()==0){
		v.push_back(std::pair<json_object*, json_object*>(key, val));
	}
	else if(this->find(key) == -1){
		v.push_back(std::pair<json_object*, json_object*>(key, val));

	}else{
		v[find(key)].second = val;

	}
}

int json_dict::find(json_object* key) const{

	int index;

	for(index = 0; index < v.size()+1; index++){
		if(index == v.size()){
			
			return -1;
		}
		if((v[index].first->to_string()) == (key->to_string())){
			return index;

		}
	}

	return index;
}

json_dict::json_dict(){

}

json_object* json_dict::parse(const char* str, int length){

	json_dict* returnvalue = new json_dict();

	int flag = 0;
	
	for(_index += 1; _index < length; _index++){


		const char* thisone = str+_index;

		char index = str[_index];

//		std::cout << _index << ": "<< index <<", flag: "<< flag << std::endl; // 디버깅용

		json_object* key;

		if(index == ':'){

			flag++;

		}
		else if(index == ' ' || index == ','){}

		else if(index == '{'){

			if(flag == 0){

				key == json_dict::parse(str, length);

			}else{
			
				returnvalue->put(key, json_dict::parse(str,length));

				flag--;
			
			}
		}
		else if(index == '['){
			if(flag == 0){

				key = json_list::parse(str, length);

			}else{

				returnvalue->put(key, json_list::parse(str, length));
				flag--;
			}

		}
		else if(index == '\'' || index == '"'){


			if(flag == 0){
				
				key = String::parse(thisone, length, index);

			}else { // flag == 1

				returnvalue->put(key, String::parse(thisone, length, index));
				flag--;
			}
		}
		else if(index >= 48 && index <= 57){

			int count = _index;

			while(str[count] >= 48 && str[count] <= 57){

				count++;
				
			}
	
			if(flag == 0){

				key = Integer::parse(thisone, count);

			}else { // flag == 1
				
				returnvalue->put(key, Integer::parse(thisone, count));

				flag--;

			}

		}
	}
	str++;
	return	returnvalue;
}
	


json_object* json_dict::operator[](json_object* key) const{

	return v[find(key)].second;
}

json_object* json_dict::operator[](const std::string& key) const{

	std::string str = '\'' + key + '\'';
	json_object* rString = json_object::parse(str);
	return v[find(rString)].second;
}

json_object* json_dict::operator[](int key) const{
	json_object* rInt = json_object::parse(std::to_string(key));
	return v[find(rInt)].second;
}

json_object::_type json_dict::type(){

	return DICT;

}

std::string json_dict::to_string(){
	
	std::string input("{");
	
	for(std::vector<std::pair<json_object*, json_object*>>::iterator it = v.begin() ;it != v.end(); it++){
		
		input.append(it->first->to_string());
		input.append(": ");
		input.append(it->second->to_string());
		if((it+1) != v.end()){
			input.append(", ");
		}
		
	}
	input.append("}");
	return input;
}
