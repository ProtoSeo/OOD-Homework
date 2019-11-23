#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"


json_list::json_list(){
	
}
json_object* json_list::parse(const char* str,int length){
	_index++;
	json_list* temp = new json_list();
	for(;str[_index]!=']';_index++){
		if(str[_index]==','||str[_index]==' '){
			continue;
		}
		if(str[_index]=='\''){
			temp->v.push_back(String::parse(str,length,'\''));
		}
		else if(str[_index]=='\"'){
			temp->v.push_back(String::parse(str,length,'\"'));
		}
		else if(str[_index]=='{'){
			temp->v.push_back(json_dict::parse(str,length));
		}
		else if(str[_index]=='['){
			temp->v.push_back(json_list::parse(str,length));		
		}
		else if (str[_index] >= '0' && str[_index] <= '9') {
			temp->v.push_back(Integer::parse(str,length));
		}
	}
	return temp;
}
json_object* json_list::operator[](int key) const {
	return v[key];
}

json_object::_type json_list::type(){
	return LIST;
}

std::string json_list::to_string(){
    std::string str = "[";
	int max = this->v.size();
	for(int i=0;i<max;i++){
		str += v[i]->to_string();
		if(max-1>i)
			str += ", ";
	}
	return str+"]";
}
