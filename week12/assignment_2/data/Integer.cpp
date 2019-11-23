#include "Integer.h"

Integer::Integer(int value){
	this->_val = value;
}
int Integer::val(){
	return _val;
}
void Integer::set_val(const int& value){
	this->_val = value;
}
json_object* Integer::parse(const char *str,int length){
	std::string newstr="";
	for(;str[_index]>='0'&&str[_index]<='9';_index++){
		newstr +=str[_index];
	}
	if (str[_index] == ':'|| str[_index] == ',' || str[_index] == ']' || str[_index] == '}')
		_index--;
	int val= atoi(newstr.c_str());
	return new Integer(val);
}
json_object::_type Integer::type(){
	return INT;
}
std::string Integer::to_string(){
	return std::to_string(_val);
}
