#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"
int json_object::_index = 0;
json_object* json_object::parse(const char* str,int length){
	_index = 0;
	json_object* tempptr = nullptr;
	for(;_index<length;_index++){
		if(str[_index]==' '){
			continue;
		}
		if(str[_index]=='\''){
			tempptr = String::parse(str,length,'\'');
		}
		else if(str[_index]=='\"'){
			tempptr = String::parse(str,length,'\"');
		}
		else if(str[_index]=='{'){
			tempptr = json_dict::parse(str,length);
		}
		else if(str[_index]=='['){
			tempptr = json_list::parse(str,length);
		}
		else if(str[_index]>='0'&&str[_index]<='9'){
			tempptr = Integer::parse(str,length);
		}
	}
	return tempptr;
}

json_object* json_object::parse(const std::string& str){
	return parse(str.c_str(),str.length());	
}
