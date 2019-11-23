#include "String.h"

String::String(const std::string& str){
	this->_val = str;
}
std::string String::val(){
	return _val;
}
void String::set_val(const std::string& str){
	this->_val = str;
}
json_object* String::parse(const char *str,int length,char base){
	std::string newstr="";
	_index++;
	for(; str[_index]!=base ;_index++){
		newstr += str[_index];
	}
	return new String(newstr);
}
json_object::_type String::type(){
	return STRING;
}
std::string String::to_string(){
	return "\'"+_val+"\'";
}


