#include "car.h"

car::car():vehicle(){}

car::car(int wheel,int speed):vehicle(wheel,speed){
	set_car_name(nullptr);
}
car::car(int wheel,int speed,char* name):vehicle(wheel,speed){
	set_car_name(name);
}
car::car(int wheel,int speed,char* name,bool has_name):vehicle(wheel,speed,has_name){
	set_car_name(name);
}
const char* car::get_class_name(){
	return "car";
}

char* car::get_car_name(){
	return this->car_name;
}
void car::set_car_name(char* name){
	this->car_name = name;
}




