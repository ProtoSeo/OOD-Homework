#include "vehicle.h"

vehicle::vehicle(){
	set_wheel_number(0);
	set_max_speed(0);
	set_has_name(false);
}
vehicle::vehicle(int wheel,int speed){
	set_wheel_number(wheel);
	set_max_speed(speed);
	set_has_name(true);
}
vehicle::vehicle(int wheel,int speed,bool has_name){
	set_wheel_number(wheel);
	set_max_speed(speed);
	set_has_name(has_name);
}

const char* vehicle::get_class_name(){
	return "vehicle";
}
bool vehicle::get_has_name(){
	return this->has_name;
}
int  vehicle::get_max_speed(){
	return this->max_speed;
}
int  vehicle::get_wheel_number(){
	return this->wheel_number;
}


void vehicle::set_wheel_number(int wheel){
	this->wheel_number = wheel;
}
void vehicle::set_max_speed(int speed){
	this->max_speed = speed;
}
void vehicle::set_has_name(bool has_name){
	this->has_name = has_name;
}

