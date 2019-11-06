#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

class bike:public vehicle{
	private:
		char* bike_name;
		int bike_number;
	public:
		bike();
		explicit bike(int wheel,int speed);
		explicit bike(int wheel,int speed,char* name,int number);
		explicit bike(int wheel,int speed,char* name,int number,bool has_name);

		int get_bike_number();
		char* get_bike_name();
		virtual const char* get_class_name();

		void set_bike_name(char* name);
		void set_bike_number(int number);

};

#endif 