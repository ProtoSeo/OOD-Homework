#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
class vehicle{
	private:
		bool has_name;
		int wheel_number;
		int max_speed;
	public:
		vehicle();
		explicit vehicle(int wheel,int speed);
		explicit vehicle(int wheel,int speed,bool has_name);
		const char* get_class_name();
		int  get_wheel_number();
		int get_max_speed();
		bool get_has_name();
		
		void set_wheel_number(int);
		void set_max_speed(int);
		void set_has_name(bool);

};
#endif
