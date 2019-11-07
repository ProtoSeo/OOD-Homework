#ifndef CAR_H
#define CAR_H

#include "vehicle.h"
class car:public vehicle{
	private: 
		char* car_name;
	public:
		car();
		explicit car(int wheel,int speed);
		explicit car(int wheel,int speed,char* name,bool has_name);
		explicit car(int wheel,int speed,char* name);

		char* get_car_name();
		const char* get_class_name();

		void set_car_name(char* name);

};



#endif
