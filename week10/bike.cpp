#include "bike.h"

bike::bike():vehicle(){}	
bike::bike(int wheel,int speed):vehicle(wheel,speed){
	set_bike_number(1);
	set_bike_name(nullptr);
}
bike::bike(int wheel,int speed,char* name,int number):vehicle(wheel,speed){
	set_bike_number(number);
	set_bike_name(name);
}

bike::bike(int wheel,int speed,char* name,int number,bool has_name):vehicle(wheel,speed,has_name){
	set_bike_number(number);
	set_bike_name(name);
}

int bike::get_bike_number(){
	return this->bike_number;
}
char* bike::get_bike_name(){
	return this->bike_name;
}

const char* bike::get_class_name(){
	return "bike";
}

void bike::set_bike_name(char* name){
	this->bike_name = name;
}

void bike::set_bike_number(int number){
	this->bike_number = number;
}
