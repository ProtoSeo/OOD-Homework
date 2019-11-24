#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"
//Constructor
json_dict::json_dict(){
	
}
//private method
void json_dict::put(json_object* key, json_object* val){	
	int temp = find(key);
	if (temp == -1) 
		v.push_back(std::make_pair(key, val));
	else	
		v[temp].second = val;
	
}
int json_dict::find(json_object* key){
	int max = v.size();
	for (int i = 0; i < max; i++) {
		if (key->type() == INT && v[i].first->type() == INT) {
			Integer* temp1 = dynamic_cast<Integer*>(key);
			Integer* temp2 = dynamic_cast<Integer*>(v[i].first);
			if (temp2->val() == temp1->val()) {
				return i;
			}
		}
		else if (key->type() == STRING && v[i].first->type() == STRING) {
			String* temp1 = dynamic_cast<String*>(key);
			String* temp2 = dynamic_cast<String*>(v[i].first);
			if (temp2->val() == temp1->val()) {
				return i;
			}
		}
		else if (key->type() == DICT && v[i].first->type() == DICT) {
			json_dict* temp1 = dynamic_cast<json_dict*>(key);
			json_dict* temp2 = dynamic_cast<json_dict*>(v[i].first);
			if (temp1->to_string() == temp2->to_string()) {
				return i;
			}
		}
		else if (key->type() == LIST && v[i].first->type() == LIST) {
			json_list* temp1 = dynamic_cast<json_list*>(key);
			json_list* temp2 = dynamic_cast<json_list*>(v[i].first);
			if (temp1->to_string() == temp2->to_string()) {
				return i;
			}
		}
	}
	return -1;
}
json_object* json_dict::parse(const char *str,int length){
	_index++;
	json_dict* dict = new json_dict();
	json_object* temp = nullptr;
	std::pair< json_object*, json_object*> temppair;
	for(;str[_index]!='}';_index++){
		if(str[_index]==' '){
			continue;
		}
		if(str[_index]==':'){
			temppair = std::make_pair(temp,nullptr);
			temp = nullptr;
			continue;
		}
		if(str[_index]==','){
			temppair.second = temp;
			temp = nullptr;
			dict->put(temppair.first,temppair.second);
			continue;
		}
		if(str[_index]=='\''){
			temp = String::parse(str,length,'\'');
		}
		else if(str[_index]=='\"'){
			temp = String::parse(str,length,'\"');
		}
		else if(str[_index]=='{'){
			temp = json_dict::parse(str,length);
		}
		else if(str[_index]=='['){
			temp = json_list::parse(str,length);
		}
		else if (str[_index] >= '0' && str[_index] <= '9') {
			temp = Integer::parse(str, length);
		}
	}
	temppair.second = temp;
	dict->put(temppair.first, temppair.second);
	return dict;
}
json_object* json_dict::operator[](const std::string& key) const{ 
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first->type() == STRING) {
			String* temp = dynamic_cast<String*>(v[i].first);
			if (key == temp->val()) {
				return v[i].second;
			}
		}
	}
	return nullptr;
}
json_object* json_dict::operator[](json_object* key) const {
	for (int i = 0; i < v.size(); i++) {
		if (key->type() == DICT && v[i].first->type() == DICT) {
			json_dict* temp1 = dynamic_cast<json_dict*>(key);
			json_dict* temp2 = dynamic_cast<json_dict*>(v[i].first);
			if (temp1->to_string() == temp2->to_string()) {
				return v[i].second;
			}
		}
		else if (key->type() == LIST && v[i].first->type() == LIST) {
			json_list* temp1 = dynamic_cast<json_list*>(key);
			json_list* temp2 = dynamic_cast<json_list*>(v[i].first);
			if (temp1->to_string() == temp2->to_string()) {
				return v[i].second;
			}
		}
	}
	return nullptr;
}
json_object* json_dict::operator[](int key) const {
	for (int i = 0; i < v.size(); i++) {			
		if (v[i].first->type() == INT) {
			Integer* temp = dynamic_cast<Integer*>(v[i].first);
			if (key == temp->val()) {
				return v[i].second;
			}
		}
	}
	return nullptr;
}
json_object::_type json_dict::type(){
	return DICT;
}
std::string json_dict::to_string(){
	std::string str = "{";
	int max = this->v.size();
	for(int i=0;i<max;i++){
		str+=v[i].first->to_string();
		str+=": ";
		str+=v[i].second->to_string();
		if(i< max-1)
			str+=", ";
	}
	return str +"}";
}
